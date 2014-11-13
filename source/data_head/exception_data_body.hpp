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
        body(text const& message);
        body(trace::entry const& origin);

        text get_message() const;
        trace::entry get_origin() const;
        trace get_trace() const;

    private:
        text m_message;
        trace::entry m_origin;
        trace m_trace;
    };
}

// sine qua non
