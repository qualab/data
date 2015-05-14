/// @author Владимир Керимов

#pragma once

#include <data/datetime>
#include <object/object_holder.hpp>
#include <data/decimal>

namespace data
{
    class datetime::holder : public object::holder
    {
    public:
        holder();

    private:
        date m_date;
        time m_time;
    };

    class date::holder : public object::holder
    {
    public:
        holder();

    private:
        int64_t m_century_day;
    };

    class time::holder : public object::holder
    {
    public:
        holder();

    private:
        decimal m_day_moment;
    };
}

// sine qua non
