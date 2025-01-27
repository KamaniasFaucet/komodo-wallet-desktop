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

//! C++ headers
#include <string>

//! Project Headers
#include "atomicdex/utilities/cpprestsdk.utilities.hpp"

namespace atomic_dex::faucet::api
{
    struct claim_request
    {
        std::string coin_name;
        std::string wallet_address;
    };
    
    pplx::task<web::http::http_response>
    claim(const claim_request& claim_request);
    
    struct claim_result
    {
        std::string message;
        std::string status;
    };
    
    [[nodiscard]]
    claim_result
    get_claim_result(const web::http::http_response& claim_response);
}