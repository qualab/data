/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for any floating and fixed point data
    class DATA_API numeric : public object
    {
    public:
        /// Create null-object of not initialized integer
        numeric();

    protected:
        /// Forward declaration of object::data
        class data;
    };
}

// sine qua non
