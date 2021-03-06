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

/* The disc_platform_defs.h specialization for the lightweight mDNS querier. */

#ifndef DISC_PLATFORM_DEFS_H_
#define DISC_PLATFORM_DEFS_H_

#define RDMNET_DISC_SERVICE_NAME_MAX_LENGTH 20

typedef struct RdmnetDiscoveredBrokerPlatformData
{
  int placeholder;
} RdmnetDiscoveredBrokerPlatformData;

typedef struct RdmnetScopeMonitorPlatformData
{
  int placeholder;
} RdmnetScopeMonitorPlatformData;

typedef struct RdmnetBrokerRegisterPlatformData
{
  int placeholder;
} RdmnetBrokerRegisterPlatformData;

#endif /* DISC_PLATFORM_DEFS_H_ */
