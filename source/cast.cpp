/// @author Владимир Керимов

#pragma once

#include <data/cast>
#include <data/text>
#include <limits>

namespace data
{
    template<>
    int64_t cast(int64_t value)
    {
        return value;
    }

    template<>
    int64_t cast(int32_t value)
    {
        return value;
    }

    template<>
    int64_t cast(int16_t value)
    {
        return value;
    }

    template<>
    int64_t cast(int8_t value)
    {
        return value;
    }

    template<>
    int64_t cast(uint64_t value)
    {
        if (value & (1LL << 63) != 0LL)
        {
            /// TODO: exception
        }
        return static_cast<int64_t>(value);
    }

    template<>
    int64_t cast(uint32_t value)
    {
        return static_cast<int32_t>(value);
    }

    template<>
    int64_t cast(uint16_t value)
    {
        return static_cast<int16_t>(value);
    }

    template<>
    int64_t cast(uint8_t value)
    {
        return static_cast<int8_t>(value);
    }

    template<>
    int64_t cast(double value)
    {
        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
        {
            /// TODO: exception
        }
        return static_cast<int64_t>(value);
    }

    template<>
    int64_t cast(float value)
    {
        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
        {
            /// TODO: exception
        }
        return static_cast<int64_t>(value);
    }

    template<>
    int64_t cast(bool value)
    {
        return value ? 1LL : 0LL;
    }

    template<>
    int64_t cast(text value)
    {
        return 0; /// TODO: text to integer
    }

    template<>
    int64_t cast(char const* value)
    {
        return 0; /// TODO: text to integer
    }

    template<>
    int64_t cast(wchar_t const* value)
    {
        return 0; /// TODO: text to integer
    }

    template<>
    int64_t cast(object value)
    {
        return value.get_as<int64_t>();
    }

    template<>
    double cast(int64_t value)
    {
        if (static_cast<int64_t>(static_cast<double>(value)) != value)
        {
            /// TODO: exception
        }
        return static_cast<double>(value);
    }

    template<>
    double cast(int32_t value)
    {
        return cast<double>(static_cast<int64_t>(value));
    }

    template<>
    double cast(int16_t value)
    {
        return cast<double>(static_cast<int64_t>(value));
    }

    template<>
    double cast(int8_t value)
    {
        return cast<double>(static_cast<int64_t>(value));
    }

    template<>
    double cast(uint64_t value)
    {
        if (static_cast<uint64_t>(static_cast<double>(value)) != value)
        {
            /// TODO: exception
        }
        return static_cast<double>(value);
    }

    template<>
    double cast(uint32_t value)
    {
        return cast<double>(static_cast<uint64_t>(value));
    }

    template<>
    double cast(uint16_t value)
    {
        return cast<double>(static_cast<uint64_t>(value));
    }

    template<>
    double cast(uint8_t value)
    {
        return cast<double>(static_cast<uint64_t>(value));
    }

    template<>
    double cast(double value)
    {
        return value;
    }

    template<>
    double cast(float value)
    {
        return static_cast<double>(value);
    }

    template<>
    double cast(bool value)
    {
        return value ? 1 : 0;
    }

    template<>
    double cast(text value)
    {
        return 0; /// TODO: text to double
    }

    template<>
    double cast(char const* value)
    {
        return 0; /// TODO: text to double
    }

    template<>
    double cast(wchar_t const* value)
    {
        return 0; /// TODO: text to double
    }

    template<>
    double cast(object value)
    {
        return value.get_as<double>();
    }


    template<>
    bool cast(int64_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(int32_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(int16_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(int8_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(uint64_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(uint32_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(uint16_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(uint8_t value)
    {
        return value != 0;
    }

    template<>
    bool cast(double value)
    {
        return value != 0;
    }

    template<>
    bool cast(float value)
    {
        return value != 0;
    }

    template<>
    bool cast(bool value)
    {
        return value;
    }

    template<>
    bool cast(text value)
    {
        return false; /// TODO: text to bool
    }

    template<>
    bool cast(char const* value)
    {
        return false; /// TODO: text to bool
    }

    template<>
    bool cast(wchar_t const* value)
    {
        return false; /// TODO: text to bool
    }

    template<>
    bool cast(object value)
    {
        return value.get_as<bool>();
    }

    template<>
    text cast(int64_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(int32_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(int16_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(int8_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(uint64_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(uint32_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(uint16_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(uint8_t value)
    {
        return text(); /// TODO: integer to text
    }

    template<>
    text cast(double value)
    {
        return text(); /// TODO: floating point value to text
    }

    template<>
    text cast(float value)
    {
        return text(); /// TODO: floating point value to text
    }

    template<>
    text cast(bool value)
    {
        return text(); /// TODO: bool to text
    }

    template<>
    text cast(text value)
    {
        return value;
    }

    template<>
    text cast(char const* value)
    {
        return text(); /// TODO: text to byte string
    }

    template<>
    text cast(wchar_t const* value)
    {
        return text(); /// TODO: text to wide string
    }

    template<>
    text cast(object value)
    {
        return value.get_as<text>();
    }
}

// sine qua non
