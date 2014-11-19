/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <data_head/exception_data.hpp>
#include <data/stacktrace>
#include <data/text>

namespace data
{
    class exception::data::body
    {
    public:
        body();
        body(text const& message);
        body(text const& message, callinfo const& origin);

        text get_message() const;
        callinfo get_origin() const;
        stacktrace get_stacktrace() const;

    private:
        const text m_message;
        callinfo m_origin;
        stacktrace m_stacktrace;
    };
}

// sine qua non
