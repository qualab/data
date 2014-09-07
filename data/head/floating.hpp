/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/cast>

namespace data
{
    /// Type for any floating point data
    class DATA_API floating : public object
    {
    public:
        /// Create null-object of not initialized integer
        floating();

        floating(double value);
        floating(std::nullptr_t);

        /// Create object and initialize by specified value
        template <typename value_type>
        floating(value_type value);

    protected:
        /// Forward declaration of object::data
        class data;

        // Access to floating::data
        friend class object;

    private:
        data* m_data;
    };

    template <typename value_type>
    floating::floating(value_type value)
    {
        set_as(cast<double>(value));
    }
}

// sine qua non
