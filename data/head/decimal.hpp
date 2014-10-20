/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for fixed decimal point data
    class DATA_API decimal : public object
    {
    public:
        /// Create decimal by textual representation
        explicit decimal(text const& value);

        /// Create decimal by single precision floating-point value
        explicit decimal(float value);

        /// Create decimal by double precision floating-point value
        explicit decimal(double value);

        /// Create decimal by integral and fractional components
        decimal(int64_t integral, uint64_t fractional);

        int64_t floor() const;

        int64_t ceil() const;

        int64_t integral() const;

        uint64_t fractional() const;

    protected:
        /// Forward declaration of object::data
        class data;

    private:
        /// Stored pointer to floating::data
        data* m_data;
    };
}

// sine qua non
