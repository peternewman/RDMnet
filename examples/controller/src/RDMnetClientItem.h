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

#pragma once

#include "rdm/message.h"
#include "rdmnet/client.h"
#include "EndpointItem.h"

BEGIN_INCLUDE_QT_HEADERS()
#include <QString>
END_INCLUDE_QT_HEADERS()

class RDMnetClientItem : public RDMnetNetworkItem
{
public:
  static const int RDMnetClientItemType = QStandardItem::UserType + 3;

  static const char* clientType2String(rpt_client_type_t type);

  // RDMnetClientItem();
  RDMnetClientItem(const ClientEntryData& entry, bool is_me);
  virtual ~RDMnetClientItem();

  virtual int type() const override;

  bool operator==(const RDMnetClientItem& other)
  {
    return (get_rpt_client_entry_data(&entry_)->client_type == get_rpt_client_entry_data(&other.entry_)->client_type) &&
           (get_rpt_client_entry_data(&entry_)->client_uid == get_rpt_client_entry_data(&other.entry_)->client_uid);
  }

  RdmUid uid() const override { return get_rpt_client_entry_data(&entry_)->client_uid; }
  const rpt_client_type_t ClientType() const { return get_rpt_client_entry_data(&entry_)->client_type; }

  void setScopeSlot(const QString& scope, uint16_t slot);
  uint16_t getScopeSlot(const QString& scope);
  void removeScopeSlot(const QString& scope);

  ClientEntryData entry_;
  std::vector<EndpointItem*> endpoints_;

protected:
  std::map<QString, uint16_t> scope_slots_;
};