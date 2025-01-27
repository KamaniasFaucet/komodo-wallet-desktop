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

#include <cassert>
#include <string>
#include <windows.h> //! HMODULE, GetModuleHandleW, GetModuleFileNameW

#include "../../portable.filesystem.hpp"

namespace antara::gaming::core::details
{
    fs::path
    binary_real_path() 
    {
        HMODULE hModule = GetModuleHandleW(nullptr);
        assert(hModule != nullptr);
        WCHAR path[MAX_PATH];
        [[maybe_unused]] auto  result = GetModuleFileNameW(hModule, path, MAX_PATH);
        assert(result);
        return fs::path(path);
    }

    fs::path
    assets_real_path() 
    {
        return binary_real_path().parent_path() / "assets";
    }
} // namespace antara::gaming::core::details