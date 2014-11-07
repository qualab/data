/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data.hpp>
#include <data/text>
#include <data/trace>

namespace data
{
    exception::exception()
        : object(m_data = new(buffer()) exception::data)
    {
    }

    exception::exception(text const& message)
    {
        // TODO: initialization exception with message
    }

    exception::exception(text const& message, char const* file, int line, char const* function)
    {
        // TODO: initialization exception with message, file name, line number and function name where exception occurs
    }

    text exception::get_message() const
    {
        return text(); /// TODO: return message
    }

    trace exception::get_trace() const
    {
        return trace(); /// TODO: return trace
    }

    char const* exception::what() const
    {
        return ""; /// TODO: return message
    }
}

// sine qua non
