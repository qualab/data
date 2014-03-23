/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for any floating point data
    class DATA_API floating : public object
    {
    public:
        /// Create null-object of not initialized integer
        floating();

        /// Create object and initialize by specified value
        template <typename value_type>
        floating(value_type value);

        /// Clone data into new object
        virtual object clone() const override;

    protected:
        /// Forward declaration of object::data
        class data;

        floating(data* new_data);

    private:
        /// Object data is lazy to initialize and copy-on-write
        lazy<data> m_data;
    };

    template <typename value_type>
    floating::floating(value_type value)
        : object(value)
    {
    }
}

// sine qua non
