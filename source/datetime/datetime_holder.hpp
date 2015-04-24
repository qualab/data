/// @author Владимир Керимов

#pragma once

#include <data/datetime>
#include <data_head/object_data.hpp>
#include <data/decimal>

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

    class date::data : public object::data
    {
    public:
        data();

    private:
        int64_t m_century_day;
    };

    class time::data : public object::data
    {
    public:
        data();

    private:
        decimal m_day_moment;
    };
}

// sine qua non
