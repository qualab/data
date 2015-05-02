/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    typedef uint8_t byte;

    /// Type of date and time with time zone
    class DATA_API bytes : public object
    {
    public:
        /// Create datetime of null value
        bytes();

        /// Get byte by value from array
        byte operator [] (int index) const;

        /// Get byte by non-constant reference from array
        byte& operator [] (int index);

    protected:
        /// Forward declaration of bytes::data
        class data;

    private:
        /// Stored pointer to bytes::data
        data* m_data;
    };
}

// sine qua non
