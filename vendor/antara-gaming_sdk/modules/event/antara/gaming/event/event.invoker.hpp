
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

//! C++ System Headers
#include <utility> ///< std::forward

//! Dependencies Headers
#include <entt/signal/dispatcher.hpp> ///< entt::dispatcher

namespace antara::gaming::event
{
    template <typename Event, typename... Arguments>
    struct invoker_dispatcher
    {
        constexpr invoker_dispatcher()  = default;

        void
        operator()(entt::dispatcher& self, Arguments&&... args)
        {
            self.trigger<Event>(std::forward<Arguments>(args)...);
        }
    };
} // namespace antara::gaming::event