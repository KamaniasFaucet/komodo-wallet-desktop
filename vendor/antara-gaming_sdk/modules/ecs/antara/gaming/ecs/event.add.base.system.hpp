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
#include <memory> ///< std::unique_ptr

//! SDK Headers
#include "antara/gaming/ecs/base.system.hpp" ///< ecs::base_system

namespace antara::gaming::ecs::event
{
    struct add_base_system
    {
        //! Typedefs
        using base_system_ptr = std::unique_ptr<ecs::base_system>;

        //! Constructor
        add_base_system(base_system_ptr system_ptr_ = nullptr) ;

        //! Fields
        std::unique_ptr<ecs::base_system> system_ptr{nullptr};
    };
} // namespace antara::gaming::ecs::event