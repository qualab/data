/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <tools/allow_null.hpp>

namespace data
{
    typedef uint8_t byte;

    /// Sequence of bytes
    class DATA_API byte_array : public object
    {
    public:
        /// Create byte array
        byte_array();

        /// Get byte by value from array
        byte operator [] (int index) const;

        /// Get byte by non-constant reference from array
        byte& operator [] (int index);

    protected:
        /// Forward declaration of bytes::data
        class holder;

    private:
        /// Stored pointer to byte_array::holder
        allow_null<holder> m_holder;
    };
}

// sine qua non
