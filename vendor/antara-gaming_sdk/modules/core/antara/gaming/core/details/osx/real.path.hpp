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

#include <array>
#include <cassert>
#include <climits>
#include <mach-o/dyld.h>
#include <string>

#include "../../portable.filesystem.hpp"

namespace antara::gaming::core::details
{
    static std::string&
    replace_all_mute(std::string& s, const std::string& from, const std::string& to) 
    {
        if (not from.empty())
        {
            for (std::size_t pos = 0; (pos = s.find(from, pos) + 1); pos += to.size()) s.replace(--pos, from.size(), to);
        }
        return s;
    }

    static std::string
    replace_all_copy(std::string s, const std::string& from, const std::string& to) 
    {
        return replace_all_mute(s, from, to);
    }

    fs::path
    binary_real_path() 
    {
        std::array<char, PATH_MAX + 1> dir_name_buffer{};
        auto                           size   = static_cast<uint32_t>(dir_name_buffer.size());
        [[maybe_unused]] int           result = _NSGetExecutablePath(dir_name_buffer.data(), &size);
        assert(result == 0);
        std::string tmp_path(dir_name_buffer.data());
        auto        final_path = replace_all_copy(tmp_path, "./", "");
        return fs::path(final_path);
    }

    fs::path
    assets_real_path() 
    {
        return binary_real_path().parent_path().parent_path() / "Resources/assets";
    }
} // namespace antara::gaming::core::details