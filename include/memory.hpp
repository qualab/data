/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/nullable>

namespace data
{
    typedef uint8_t byte;

    /// Sequence of bytes
    class DATA_API memory : public object
    {
    public:
        /// Create byte array
        memory();

        /// Get byte by value from array
        byte operator [] (int index) const;

        /// Get byte by non-constant reference from array
        byte& operator [] (int index);

        template <typename value_type>
        value_type& as(int offset = 0);

        template <typename value_type>
        value_type const& as(int offset = 0) const;

    protected:
        class holder;
        class instance;

    private:
        /// Stored pointer to byte_array::holder
        nullable<holder> m_holder;
    };
}

// sine qua non
