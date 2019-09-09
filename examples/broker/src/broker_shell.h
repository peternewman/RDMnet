/******************************************************************************
************************* IMPORTANT NOTE -- READ ME!!! ************************
*******************************************************************************
* THIS SOFTWARE IMPLEMENTS A **DRAFT** STANDARD, BSR E1.33 REV. 77. UNDER NO
* CIRCUMSTANCES SHOULD THIS SOFTWARE BE USED FOR ANY PRODUCT AVAILABLE FOR
* GENERAL SALE TO THE PUBLIC. DUE TO THE INEVITABLE CHANGE OF DRAFT PROTOCOL
* VALUES AND BEHAVIORAL REQUIREMENTS, PRODUCTS USING THIS SOFTWARE WILL **NOT**
* BE INTEROPERABLE WITH PRODUCTS IMPLEMENTING THE FINAL RATIFIED STANDARD.
*******************************************************************************
* Copyright 2019 ETC Inc.
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

#ifndef _BROKER_SHELL_H_
#define _BROKER_SHELL_H_

#include <string>
#include <vector>
#include <array>
#include <atomic>
#include "etcpal/inet.h"
#include "etcpal/log.h"
#include "rdmnet/broker.h"

// BrokerShell : Platform-neutral wrapper around the Broker library from a generic console
// application. Instantiates and drives the Broker library.

class BrokerShell : public RDMnet::BrokerNotify
{
public:
  typedef std::array<uint8_t, ETCPAL_NETINTINFO_MAC_LEN> MacAddr;

  void Run(RDMnet::BrokerLog* log, RDMnet::BrokerSocketManager* socket_mgr);
  static void PrintVersion();

  // Options to set from the command line; must be set BEFORE Run() is called.
  void SetInitialScope(const std::string& scope) { initial_data_.scope = scope; }
  void SetInitialIfaceList(const std::vector<EtcPalIpAddr>& ifaces) { initial_data_.ifaces = ifaces; }
  void SetInitialMacList(const std::vector<MacAddr>& macs) { initial_data_.macs = macs; }
  void SetInitialPort(uint16_t port) { initial_data_.port = port; }
  void SetInitialLogLevel(int level) { initial_data_.log_mask = ETCPAL_LOG_UPTO(level); }

  void NetworkChanged();
  void AsyncShutdown();

private:
  void ScopeChanged(const std::string& new_scope) override;
  void PrintWarningMessage();

  std::vector<EtcPalIpAddr> GetInterfacesToListen();
  std::vector<EtcPalIpAddr> ConvertMacsToInterfaces(const std::vector<MacAddr>& macs);
  void ApplySettingsChanges(RDMnet::BrokerSettings& settings, std::vector<EtcPalIpAddr>& new_addrs);

  struct InitialData
  {
    std::string scope{E133_DEFAULT_SCOPE};
    std::vector<EtcPalIpAddr> ifaces;
    std::vector<MacAddr> macs;
    uint16_t port{0};
    int log_mask{ETCPAL_LOG_UPTO(ETCPAL_LOG_INFO)};
  } initial_data_;

  RDMnet::BrokerLog* log_{nullptr};
  std::atomic<bool> restart_requested_{false};
  bool shutdown_requested_{false};
  std::string new_scope_;
};

#endif  // _BROKER_SHELL_H_