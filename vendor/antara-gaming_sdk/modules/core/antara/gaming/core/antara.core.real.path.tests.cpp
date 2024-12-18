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

#include "antara/gaming/core/real.path.hpp"
#include <doctest/doctest.h>

namespace antara::gaming::core::tests
{
    TEST_CASE("binary_real_path not empty")
    {
        auto result = binary_real_path().string();
        MESSAGE("binary real path " << result);
        CHECK_FALSE(result.empty());
    }

    TEST_CASE("assets_real_path not empty")
    {
        auto result = assets_real_path().string();
        MESSAGE("assets real path " << result);
        CHECK_FALSE(result.empty());
    }
} // namespace antara::gaming::core::tests