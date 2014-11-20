/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data_body.hpp>

namespace data
{
    exception::data::body::body()
    {
    }

    exception::data::body::body(text const& message)
        : m_message(message), m_origin(), m_stacktrace(stacktrace::thread_stack())
    {
    }

    exception::data::body::body(text const& message, callinfo const& origin)
        : m_message(message), m_origin(origin), m_stacktrace(stacktrace::thread_stack())
    {
    }

    text exception::data::body::get_message() const
    {
        return m_message;
    }

    callinfo exception::data::body::get_origin() const
    {
        return m_origin;
    }

    stacktrace exception::data::body::get_stacktrace() const
    {
        return m_stacktrace;
    }
}

// sine qua non
