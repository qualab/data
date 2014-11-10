﻿/// @author Владимир Керимов

#pragma once

#include <data_head/exception_data.hpp>
#include <data/text>
#include <data/trace>

namespace data
{
    exception::exception()
        : object(m_data = new(buffer()) exception::data)
    {
        DATA_CALL_INFO("Create data::exception without any information by default.");
        static_assert(sizeof(exception::data) <= data_max_size, "Data size of data::exception class have greater size than provided by base data::object class.");
    }

    exception::exception(text const& message)
        : object(m_data = new(buffer()) exception::data(message))
    {
        DATA_CALL_INFO("Create data::exception with message but without information about where exception is origin from.");
    }

    exception::exception(text const& message, char const* file, int line, char const* function)
        : object(m_data = new(buffer()) exception::data(message, file, line, function))
    {
        DATA_CALL_INFO("Create data::exception with message and information about where exception is origin from.");
    }

    text exception::get_message() const
    {
        DATA_CALL_INFO("Get the message from object of data::exception.");
        return m_data->get_message();
    }

    trace exception::get_trace() const
    {
        DATA_CALL_INFO("Get stack trace from where exception is origin from.");
        return m_data->get_trace();
    }

    char const* exception::what() const
    {
        DATA_CALL_INFO("Get the message from object of data::exception as byte character string. Implementation of method what() of standard std::exception.");
        return m_data->get_message().byte_char();
    }
}

// sine qua non
