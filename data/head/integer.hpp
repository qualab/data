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

        /// Create integer object initialized by 64-bit signed integer
        integer(int64_t value);

        /// Create integer object initialized by null
        integer(std::nullptr_t);

        /// Create object and initialize by specified value
        template <typename value_type>
        integer(value_type value);

    protected:
        /// Forward declaration of object::data
        class data;

        /// Create integer object initialized by prepared data
        integer(std::shared_ptr<data>&& prepared_data);

        /// Access for integer::data
        friend class object;

    private:
        /// Reference to integer::data
        data* m_data;
    };

    template <typename value_type>
    integer::integer(value_type value)
    {
        set_as(cast<int64_t>(value));
    }
}

// sine qua non
