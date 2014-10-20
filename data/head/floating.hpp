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
        /// Create null-object of not initialized floating-point value
        floating();

        /// Create floating-point object initialized by double precision real value
        floating(double value);

        /// Create floating-point object initialized by null pointer
        floating(std::nullptr_t);

        /// Create object and initialize by specified value
        template <typename value_type>
        floating(value_type value);

        /// Set floating-point value to double-precision real value
        void set_value(double value);

        /// Get floating-point value as double-precision real value
        double get_value() const;

    protected:
        /// Forward declaration of object::data
        class data;

        // Access to floating::data
        friend class object;

    private:
        /// Stored pointer to floating::data
        data* m_data;
    };

    template <typename value_type>
    floating::floating(value_type value)
    {
        set_as(cast<double>(value));
    }
}

// sine qua non
