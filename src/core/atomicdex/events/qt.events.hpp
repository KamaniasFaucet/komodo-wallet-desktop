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

#include <QString>

namespace atomic_dex
{
    struct swap_status_notification
    {
        QString uuid;
        QString prev_status;
        QString new_status;
        QString base;
        QString rel;
        QString human_date;
    };

    struct balance_update_notification
    {
        bool    am_i_sender; // Received / Successfully Send
        QString amount;      // 4
        QString ticker;      // RICK
        QString human_date;
        qint64  timestamp;
    };

    struct multi_ticker_enabled
    {
        QString ticker;
    };
} // namespace atomic_dex
