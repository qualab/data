/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <data_head/object_data.hpp>
#include <data/trace>
#include <data/text>

namespace data
{
    class exception::data : public object::data
    {
    public:
        data(text const& message, trace const& traceback);

        text get_message() const;
        trace get_trace() const;

    private:
        trace m_trace;
        text m_message;
    };
}

// sine qua non
