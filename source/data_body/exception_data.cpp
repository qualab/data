﻿/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data_body.hpp>
#include <data/trace>

namespace data
{
    exception::data::data()
    {
    }

    exception::data::data(text const& message, text const& file, int line, text const& function)
        : m_body(new exception::data::body(message, trace::stack_trace().append(trace::entry(file, line, function)))
    {
    }

    text exception::data::get_message() const
    {
        return m_body->get_message();
    }

    trace exception::data::get_trace() const
    {
        return m_body->get_trace();
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
