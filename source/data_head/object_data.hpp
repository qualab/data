/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    // base class for data of object
    class object::data
    {
    public:
        // create null object
        data();

        // destruct data
        virtual ~data();

        // check is data null
        virtual bool is_null() const;

        // clone data of object
        virtual std::shared_ptr<object::data> clone() const;
    };
}

// sine qua non
