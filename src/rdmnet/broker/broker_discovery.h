/******************************************************************************
************************* IMPORTANT NOTE -- READ ME!!! ************************
*******************************************************************************
* THIS SOFTWARE IMPLEMENTS A **DRAFT** STANDARD, BSR E1.33 REV. 63. UNDER NO
* CIRCUMSTANCES SHOULD THIS SOFTWARE BE USED FOR ANY PRODUCT AVAILABLE FOR
* GENERAL SALE TO THE PUBLIC. DUE TO THE INEVITABLE CHANGE OF DRAFT PROTOCOL
* VALUES AND BEHAVIORAL REQUIREMENTS, PRODUCTS USING THIS SOFTWARE WILL **NOT**
* BE INTEROPERABLE WITH PRODUCTS IMPLEMENTING THE FINAL RATIFIED STANDARD.
*******************************************************************************
* Copyright 2018 ETC Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************
* This file is a part of RDMnet. For more information, go to:
* https://github.com/ETCLabs/RDMnet
******************************************************************************/

/// \file broker_discovery.h
/// \brief Handles the Broker's DNS registration and discovery of other Brokers.
/// \author Sam Kearney
#ifndef _BROKER_DISCOVERY_H_
#define _BROKER_DISCOVERY_H_

#include <string>
#include <vector>
#include "lwpa/error.h"
#include "lwpa/int.h"
#include "rdmnet/broker.h"
#include "rdmnet/core/discovery.h"

/// A callback interface for notifications from a BrokerDiscoveryManager.
class BrokerDiscoveryManagerNotify
{
public:
  /// A %Broker was registered with the information indicated by broker_info.
  virtual void BrokerRegistered(const RdmnetBrokerDiscInfo &broker_info, const std::string &assigned_service_name) = 0;
  /// A %Broker was found at the same scope as the one which was previously registered.
  virtual void OtherBrokerFound(const RdmnetBrokerDiscInfo &broker_info) = 0;
  /// A previously-found non-local %Broker has gone away.
  virtual void OtherBrokerLost(const std::string &service_name) = 0;
  /// An error occurred while registering a %Broker's service instance.
  virtual void BrokerRegisterError(const RdmnetBrokerDiscInfo &broker_info, int platform_error) = 0;
};

/// A wrapper for the RDMnet Discovery library for use by Brokers.
class BrokerDiscoveryManager
{
public:
  BrokerDiscoveryManager(BrokerDiscoveryManagerNotify *notify);
  virtual ~BrokerDiscoveryManager();

  lwpa_error_t RegisterBroker(const RDMnet::BrokerDiscoveryAttributes &disc_attributes, const LwpaUuid &local_cid,
                              const std::vector<LwpaIpAddr> &listen_addrs, uint16_t listen_port);
  void UnregisterBroker();
  void Standby();
  lwpa_error_t Resume();

protected:
  static void BrokerFound(const char *scope, const RdmnetBrokerDiscInfo *broker_info, void *context);
  static void BrokerLost(const char *service_name, void *context);
  static void ScopeMonitorError(const RdmnetScopeMonitorInfo *scope_info, int platform_error, void *context);
  static void BrokerRegistered(const RdmnetBrokerDiscInfo *broker_info, const char *assigned_service_name,
                               void *context);
  static void BrokerRegisterError(const RdmnetBrokerDiscInfo *broker_info, int platform_error, void *context);

  BrokerDiscoveryManagerNotify *notify_{nullptr};
  RdmnetBrokerDiscInfo cur_info_;
  bool cur_info_valid_{false};
};

#endif  // _BROKER_DISCOVERY_H_
