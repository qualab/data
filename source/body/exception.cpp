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

    exception::exception(text const& message, text const& file, int line, text const& function)
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

    operation_not_supported::operation_not_supported()
    {
    }

    operation_not_supported::operation_not_supported(text const& message)
        : exception(message)
    {
    }

    operation_not_supported::operation_not_supported(text const& message, text const& file, int line, text const& function)
        : exception(message, file, line, function)
    {
    }

    nonexistent_type_cast::nonexistent_type_cast()
    {
    }

    nonexistent_type_cast::nonexistent_type_cast(text const& message)
        : exception(message)
    {
    }

    nonexistent_type_cast::nonexistent_type_cast(text const& message, text const& file, int line, text const& function)
        : exception(message, file, line, function)
    {
    }
}

// sine qua non
