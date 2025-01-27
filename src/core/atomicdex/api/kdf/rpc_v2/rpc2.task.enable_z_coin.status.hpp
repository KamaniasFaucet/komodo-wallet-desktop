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

// Std Headers
#include <optional>

// Deps Headers
#include <nlohmann/json.hpp>

//! Project Headers
#include "atomicdex/api/kdf/generic.error.hpp"

namespace atomic_dex::kdf
{
    struct enable_z_coin_status_request
    {
        int         task_id;
    };

    void to_json(nlohmann::json& j, const enable_z_coin_status_request& request);

    struct enable_z_coin_status_answer_success
    {
        std::string status{"disabled"};
        std::string details{"N/A"};
        std::optional<std::string> coin;
        std::optional<std::string> address;
        std::optional<std::string> current_scanned_block;
        std::optional<std::string> latest_block;
        std::optional<std::string> current_block;
        std::optional<std::string> wallet_type;
        std::optional<std::string> spendable_balance;
        std::optional<std::string> unspendable_balance;
    };

    void from_json(const nlohmann::json& j, enable_z_coin_status_answer_success& answer);

    struct enable_z_coin_status_answer
    {
        std::optional<enable_z_coin_status_answer_success> result;
        std::optional<generic_answer_error>              error;
        std::string                                      raw_result;      ///< internal
        int                                              rpc_result_code; ///< internal
    };

    void from_json(const nlohmann::json& j, enable_z_coin_status_answer& answer);
}

namespace atomic_dex
{
    using t_enable_z_coin_status_request         = kdf::enable_z_coin_status_request;
    using t_enable_z_coin_status_answer          = kdf::enable_z_coin_status_answer;
    using t_enable_z_coin_status_answer_success  = kdf::enable_z_coin_status_answer_success;
} // namespace atomic_dex
