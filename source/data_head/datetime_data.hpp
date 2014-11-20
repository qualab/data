/// @author Владимир Керимов

#pragma once

#include <data/datetime>
#include <data_head/object_data.hpp>

namespace data
{
    class datetime::data : public object::data
    {
    public:
        data();

    private:
        date m_date;
        time m_time;
    };
}

// sine qua non
