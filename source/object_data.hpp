/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    class object::data
    {
    public:
        data();
        virtual ~data();
        virtual bool is_null() const;

        virtual int64_t get_as_int64() const;
        virtual double get_as_double() const;
        virtual bool get_as_bool() const;
    };
}

// sine qua non
