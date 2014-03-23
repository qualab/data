/// @author Владимир Керимов

#pragma once

#include <data/object>

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

        /// Clone data into new object
        virtual object clone() const override;

    protected:
        /// Forward declaration of object::data
        class data;

        /// Create integer by prepared data
        integer(data* new_data);

    private:
        /// Object data is lazy to initialize and copy-on-write
        lazy<data> m_data;
    };

    template <typename value_type>
    integer::integer(value_type value)
        : object(value)
    {
    }
}

// sine qua non
