/// @author Владимир Керимов

#pragma once

#include "exception_data.hpp"

namespace data
{
    exception::exception()
    {
    }

    char const* exception::what() const
    {
        return ""; /// TODO: return message
    }
}

// sine qua non
