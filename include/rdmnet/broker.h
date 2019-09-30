/******************************************************************************
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
 ******************************************************************************
 * This file is a part of RDMnet. For more information, go to:
 * https://github.com/ETCLabs/RDMnet
 *****************************************************************************/

/// \file rdmnet/broker.h
/// \brief A platform-neutral RDMnet Broker implementation.
/// \author Nick Ballhorn-Wagner and Sam Kearney
#ifndef _RDMNET_BROKER_H_
#define _RDMNET_BROKER_H_

#include <memory>
#include <string>

#include "etcpal/int.h"
#include "etcpal/uuid.h"
#include "etcpal/socket.h"
#include "rdm/uid.h"
#include "rdmnet/defs.h"
#include "rdmnet/broker/log.h"

class BrokerCore;

/// \defgroup rdmnet_broker RDMnet Broker Library
/// \brief A platform-neutral RDMnet %Broker implementation.
/// @{
///

/// A namespace to contain the public Broker classes
namespace rdmnet
{
/// Settings for the Broker's DNS Discovery functionality.
struct BrokerDiscoveryAttributes
{
  /// Your unique name for this %Broker DNS-SD service instance. The discovery library uses
  /// standard mechanisms to ensure that this service instance name is actually unique;
  /// however, the application should make a reasonable effort to provide a name that will
  /// not conflict with other %Brokers.
  std::string dns_service_instance_name;

  /// A string to identify the manufacturer of this %Broker instance.
  std::string dns_manufacturer{"Generic Manufacturer"};
  /// A string to identify the model of product in which the %Broker instance is included.
  std::string dns_model{"Generic RDMnet Broker"};

  /// The Scope on which this %Broker should operate. If empty, the default RDMnet scope is used.
  std::string scope{E133_DEFAULT_SCOPE};
};

/// A group of settings for Broker operation.
struct BrokerSettings
{
  EtcPalUuid cid{};  ///< The Broker's CID.

  enum UidType
  {
    kStaticUid,
    kDynamicUid
  } uid_type{kDynamicUid};
  RdmUid uid{0, 0};  ///< The Broker's UID.

  void SetDynamicUid(uint16_t manufacturer_id)
  {
    RDMNET_INIT_DYNAMIC_UID_REQUEST(&uid, manufacturer_id);
    uid_type = kDynamicUid;
  }
  void SetStaticUid(const RdmUid& uid_in)
  {
    uid = uid_in;
    uid_type = kStaticUid;
  }

  BrokerDiscoveryAttributes disc_attributes;

  /// The maximum number of client connections supported. 0 means infinite.
  unsigned int max_connections{0};
  /// The maximum number of controllers allowed. 0 means infinite.
  unsigned int max_controllers{0};
  /// The maximum number of queued messages per controller. 0 means infinite.
  unsigned int max_controller_messages{500};
  /// The maximum number of devices allowed.  0 means infinite.
  unsigned int max_devices{0};
  /// The maximum number of queued messages per device. 0 means infinite.
  unsigned int max_device_messages{500};
  /// If you reach the number of max connections, this number of tcp-level connections are still
  /// supported to reject the connection request.
  unsigned int max_reject_connections{1000};

  BrokerSettings() {}
  /// Initialize a BrokerSettings with a static UID.
  BrokerSettings(const RdmUid& static_uid) { SetStaticUid(static_uid); }
  /// Initialize a BrokerSettings with a dynamic UID (provide the manufacturer ID).
  BrokerSettings(uint16_t rdm_manu_id) { SetDynamicUid(rdm_manu_id); }
};

/// A callback interface for notifications from the Broker.
class BrokerNotify
{
public:
  /// The Scope of the Broker has changed via RDMnet configuration. The Broker should be restarted.
  virtual void ScopeChanged(const std::string& new_scope) = 0;
};

/// \brief Defines an instance of RDMnet %Broker functionality.
///
/// After instantiatiation, call Startup() to start Broker services on a set of network interfaces.
/// Starts some threads (defined in broker/threads.h) to handle messages and connections.
/// Periodically call Tick() to handle some cleanup and housekeeping.
/// Call Shutdown() at exit, when Broker services are no longer needed, or when a setting has
/// changed.
class Broker
{
public:
  Broker(BrokerLog* log, BrokerNotify* notify);
  virtual ~Broker();

  bool Startup(const BrokerSettings& settings, uint16_t listen_port, std::vector<EtcPalIpAddr>& listen_addrs);
  void Shutdown();
  void Tick();

  void GetSettings(BrokerSettings& settings) const;

private:
  std::unique_ptr<BrokerCore> core_;
};

};  // namespace rdmnet

/// @}

#endif  // _RDMNET_BROKER_H_
