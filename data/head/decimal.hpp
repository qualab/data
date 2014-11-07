/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for fixed decimal point data
    class DATA_API decimal : public object
    {
    public:
        /// Create decimal with value of zero
        decimal();

        /// Create decimal by textual representation
        explicit decimal(text const& value);

        /// Create decimal by single precision floating-point value
        explicit decimal(float value);

        /// Create decimal by double precision floating-point value
        explicit decimal(double value);

        /// Create decimal by 64-bit signed integer
        explicit decimal(int64_t value);

        /// Create decimal by 32-bit signed integer
        explicit decimal(int32_t value);

        /// Create decimal by 16-bit signed integer
        explicit decimal(int16_t value);

        /// Create decimal by 8-bit signed integer
        explicit decimal(int8_t value);

        /// Create decimal by 64-bit unsigned integer
        explicit decimal(uint64_t value);

        /// Create decimal by 32-bit unsigned integer
        explicit decimal(uint32_t value);

        /// Create decimal by 16-bit unsigned integer
        explicit decimal(uint16_t value);

        /// Create decimal by 8-bit unsigned integer
        explicit decimal(uint8_t value);

        /// Create decimal by integral and fractional components
        decimal(int64_t integral, uint64_t fractional);

        int64_t intfloor() const;

        uint64_t multifract() const;

    protected:
        /// Forward declaration of object::data
        class data;

    private:
        /// Stored pointer to floating::data
        data* m_data;
    };
}

// sine qua non
