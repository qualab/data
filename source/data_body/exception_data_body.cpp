/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data_body.hpp>

namespace data
{
    exception::data::body::body()
    {
    }

    exception::data::body::body(text const& message, trace const& traceback)
        : m_trace(traceback), m_message(message)
    {
    }

    text exception::data::body::get_message() const
    {
        return m_message;
    }

    trace exception::data::body::get_trace() const
    {
        return m_trace;
    }
}

// sine qua non
