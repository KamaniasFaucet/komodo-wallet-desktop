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

#include "antara/gaming/core/api.scaling.hpp"

#ifdef _WIN32

#    include "antara/gaming/core/details/windows/api.scaling.hpp"

#elif __APPLE__

#    include "antara/gaming/core/details/osx/api.scaling.hpp"

#elif __linux__

#    include "antara/gaming/core/details/linux/api.scaling.hpp"

#elif EMSCRIPTEN
#    include "antara/gaming/core/details/emscripten/api.scaling.hpp"
#endif

namespace antara::gaming::core
{
    bool
    is_high_dpi_capable() 
    {
        return details::is_high_dpi_capable();
    }

    std::pair<float, float>
    get_scaling_factor() 
    {
        return details::get_scaling_factor();
    }
} // namespace antara::gaming::core