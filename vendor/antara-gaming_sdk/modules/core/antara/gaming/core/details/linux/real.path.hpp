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

#include <string>
#include <unistd.h> //! getpid()

#include "../../portable.filesystem.hpp"

namespace antara::gaming::core::details
{
    fs::path
    binary_real_path() 
    {
        return fs::read_symlink("/proc/" + std::to_string(getpid()) + "/exe");
    }

    fs::path
    assets_real_path() 
    {
        return binary_real_path().parent_path().parent_path() / "share/assets/";
    }
} // namespace antara::gaming::core::details