/// @author Владимир Керимов

#pragma once

#include <stacktrace/stacktrace_holder.hpp>

namespace data
{
    exception::data::data()
    {
    }

    exception::data::data(text const& message)
        : m_body(new exception::data::body(message))
    {
    }

    exception::data::data(text const& message, char const* file, int line, char const* function)
        : m_body(new exception::data::body(message, callinfo(message.byte_c_str(), file, line, function)))
    {
    }

    text exception::data::get_message() const
    {
        return m_body->get_message();
    }

    stacktrace exception::data::get_stacktrace() const
    {
        return m_body->get_stacktrace();
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
