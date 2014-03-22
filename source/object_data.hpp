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
    };
}

// sine qua non
