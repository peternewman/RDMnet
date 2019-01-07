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

#pragma once

#include "RDMnetNetworkModel.h"
#include "ControllerUtils.h"

BEGIN_INCLUDE_QT_HEADERS()
#include <QSortFilterProxyModel>
END_INCLUDE_QT_HEADERS()

class SimpleNetworkProxyModel : public QSortFilterProxyModel
{
  Q_OBJECT

private:
  RDMnetNetworkModel *sourceNetworkModel;

public slots:
  void directChildrenRevealed(const QModelIndex &parentIndex);

signals:
  void expanded(const QModelIndex &sourceModelIndex);

public:
  SimpleNetworkProxyModel();
  ~SimpleNetworkProxyModel();

  // QModelIndex mapToSource(const QModelIndex &proxyIndex) const Q_DECL_OVERRIDE;
  // QModelIndex mapFromSource(const QModelIndex &sourceIndex) const Q_DECL_OVERRIDE;

  // QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const
  // Q_DECL_OVERRIDE; QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;

  // int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
  // int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

  // bool hasChildren(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

  void setSourceModel(QAbstractItemModel *sourceModel) Q_DECL_OVERRIDE;

protected:
  bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const Q_DECL_OVERRIDE;

private:
  // Q_DECLARE_PRIVATE(QIdentityProxyModel)
};
