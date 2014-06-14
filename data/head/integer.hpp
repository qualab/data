/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/cast>

namespace data
{
    /// Type for any integer
    class DATA_API integer : public object
    {
    public:
        /// Create null-object of not initialized integer
        integer();

        /// Create object and initialize by specified value
        template <typename value_type>
        integer(value_type value);

    protected:
        /// Forward declaration of object::data
        class data;

        /// Access for integer::data
        friend class object;
    };

    template <typename value_type>
    integer::integer(value_type value)
        : object(cast<int64_t>(value))
    {
    }
}

// sine qua non
