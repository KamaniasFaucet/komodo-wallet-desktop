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

#include <optional>
#include <string>

#include <nlohmann/json_fwd.hpp> //> nlohmann::json

#include "atomicdex/api/kdf/rpc.hpp"
#include "atomicdex/api/kdf/balance_infos.hpp"

namespace atomic_dex::kdf
{
    struct enable_tendermint_token_rpc
    {
        static constexpr auto endpoint  = "enable_tendermint_token";
        static constexpr bool is_v2     = true;
        
        struct expected_request_type
        {
            std::string                                             ticker;
            struct { std::optional<int> required_confirmations; }   activation_params;
        };
        
        struct expected_result_type
        {
            std::string                                     platform_coin;
            std::unordered_map<std::string, balance_infos>   balances;
        };

        using expected_error_type = rpc_basic_error_type;

        expected_request_type                  request;
        std::optional<expected_result_type>    result;
        std::optional<expected_error_type>     error;
        std::string                            raw_result;
    };

    using enable_tendermint_token_rpc_request    = enable_tendermint_token_rpc::expected_request_type;
    using enable_tendermint_token_rpc_result     = enable_tendermint_token_rpc::expected_result_type;
    using enable_tendermint_token_rpc_error      = enable_tendermint_token_rpc::expected_error_type;

    void to_json(nlohmann::json& j, const enable_tendermint_token_rpc_request& request);
    void from_json(const nlohmann::json& j, enable_tendermint_token_rpc_result& in);
}