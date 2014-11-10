/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <data_head/exception_data.hpp>
#include <data/trace>
#include <data/text>

namespace data
{
    class exception::data::body
    {
    public:
        body();
        body(text const& message, trace::entry const& origin);

        text get_message() const;
        trace get_trace() const;
        trace::entry get_origin() const;

    private:
        trace m_trace;
        trace::entry m_origin;
        text m_message;
    };
}

// sine qua non
