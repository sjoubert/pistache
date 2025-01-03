/*
 * SPDX-FileCopyrightText: 2020 Michael Ellison
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* log.cc
   Michael Ellison, 27 May 2020

   String logger implementations - to be used via the macros defined in log.h,
   or passed into a Pistache library function as a logging endpoint.
*/

#include <iostream>

#include <pistache/pist_syslog.h>
#include <pistache/string_logger.h>

namespace Pistache::Log
{

    void StringToStreamLogger::log(Level level, const std::string& message)
    {
        if (out_ && isEnabledFor(level))
        {
            (*out_) << message << std::endl;

            // Save in syslog / os_log as well
            PSLogNoLocFn(static_cast<int>(level),
                         false, // Don't send to stdout - just did that
                         "%s", message.c_str());
        }
    }

    bool StringToStreamLogger::isEnabledFor(Level level) const
    {
        return static_cast<int>(level) >= static_cast<int>(level_);
    }

} // namespace Pistache::Log
