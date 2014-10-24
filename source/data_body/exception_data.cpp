/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data.hpp>

namespace data
{
    exception::data::data(text const& message, trace const& traceback)
        : m_trace(traceback), m_message(message)
    {
    }

    text exception::data::get_message() const
    {
        return m_message;
    }

    trace exception::data::get_trace() const
    {
        return m_trace;
    }

    object::data* exception::data::copy_to(void* address) const
    {
        return new(address) exception::data(*this);
    }

    object::data* exception::data::move_to(void* address) const
    {
        return new(address) exception::data(std::move(*this));
    }
}

// sine qua non
