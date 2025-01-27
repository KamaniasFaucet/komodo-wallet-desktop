/******************************************************************************
 * Copyright © 2013-2024 The Dexa.One Developers.                      *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * Dexa.One software, including this file may be copied, modified,     *
 * propagated or distributed except according to the terms contained in the   *
 * LICENSE file                                                               *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/

#pragma once

#include <QSortFilterProxyModel>

namespace atomic_dex
{
    class transactions_proxy_model final : public QSortFilterProxyModel
    {
        Q_OBJECT

    public:
        transactions_proxy_model(QObject* parent);
        ~transactions_proxy_model() final = default;

    protected:
        // Override
        [[nodiscard]] bool lessThan(const QModelIndex& source_left, const QModelIndex& source_right) const final;
    };
}
