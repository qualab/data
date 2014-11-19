/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data_body.hpp>

namespace data
{
    exception::data::body::body()
    {
    }

    exception::data::body::body(text const& message)
        : m_message(message), m_origin(), m_trace(trace::thread_stack())
    {
    }

    exception::data::body::body(text const& message, trace::entry const& origin)
        : m_message(message), m_origin(origin), m_trace(trace::thread_stack())
    {
    }

    text exception::data::body::get_message() const
    {
        return m_message;
    }

    trace::entry exception::data::body::get_origin() const
    {
        return m_origin;
    }

    trace exception::data::body::get_trace() const
    {
        return m_trace;
    }
}

// sine qua non
