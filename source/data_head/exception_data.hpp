/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <data_head/object_data.hpp>
#include <data/text>

namespace data
{
    class exception::data : public object::data
    {
    public:
        data();

    private:
        text m_message;
        text m_trace;
    };
}

// sine qua non
