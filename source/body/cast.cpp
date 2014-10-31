/// @author Владимир Керимов

#pragma once

#include <data/cast>
#include <data/text>
#include <type_traits>
#include <limits>

namespace data
{
//    template <typename result_type, typename value_type>
//    inline result_type int_to_smaller(value_type value)
//    {
//        if (value > static_cast<value_type>(std::numeric_limits<result_type>::max) ||
//            value < static_cast<value_type>(std::numeric_limits<result_type>::min))
//        {
//            DATA_THROW_EXCEPTION();
//        }
//        return static_cast<result_type>(value);
//    }
//
//    template <typename result_type, typename value_type>
//    inline result_type int_to_greater(value_type value)
//    {
//        return static_cast<result_type>(value);
//    }
//
//    template <typename result_type, typename value_type>
//    inline result_type unsigned_to_signed(value_type value)
//    {
//
//    }
//
////  int64_t ----------------------------------------------------------------------
//
//    template <>
//    int64_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int64_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int64_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int64_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int64_t cast(uint64_t value)
//    {
//        if ((value & (1LL << 63)) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int64_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    int64_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    int64_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    int64_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int64_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int64_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    int64_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int64_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int64_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int64_t cast(object value)
//    {
//        return value.as<int64_t>();
//    }
//
////  uint64_t -------------------------------------------------------------------
//
//    template<>
//    uint64_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint64_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint64_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint64_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint64_t cast(uint64_t value)
//    {
//        if ((value & (1LL << 63)) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint64_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    uint64_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    uint64_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    uint64_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint64_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint64_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    uint64_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint64_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint64_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint64_t cast(object value)
//    {
//        return value.as<int64_t>();
//    }
//
////  int32_t ----------------------------------------------------------------------
//
//    template<>
//    int32_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int32_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int32_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int32_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int32_t cast(uint64_t value)
//    {
//        if (value & (1LL << 63) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int32_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    int32_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    int32_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    int32_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int32_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int32_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    int32_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int32_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int32_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int32_t cast(object value)
//    {
//        return value.get_as<int64_t>();
//    }
//
////  uint32_t ---------------------------------------------------------------------
//
//    template<>
//    uint32_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint32_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint32_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint32_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint32_t cast(uint64_t value)
//    {
//        if (value & (1LL << 63) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint32_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    uint32_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    uint32_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    uint32_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint32_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint32_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    uint32_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint32_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint32_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint32_t cast(object value)
//    {
//        return value.get_as<int64_t>();
//    }
//
////  int16_t ----------------------------------------------------------------------
//
//    template<>
//    int16_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int16_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int16_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int16_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int16_t cast(uint64_t value)
//    {
//        if (value & (1LL << 63) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int16_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    int16_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    int16_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    int16_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int16_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int16_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    int16_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int16_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int16_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int16_t cast(object value)
//    {
//        return value.get_as<int64_t>();
//    }
//
////  uint16_t ---------------------------------------------------------------------
//
//    template<>
//    uint16_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint16_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint16_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint16_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint16_t cast(uint64_t value)
//    {
//        if (value & (1LL << 63) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint16_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    uint16_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    uint16_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    uint16_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint16_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint16_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    uint16_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint16_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint16_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint16_t cast(object value)
//    {
//        return value.get_as<int64_t>();
//    }
//
////  int8_t -----------------------------------------------------------------------
//
//    template<>
//    int8_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int8_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int8_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int8_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    int8_t cast(uint64_t value)
//    {
//        if (value & (1LL << 63) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int8_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    int8_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    int8_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    int8_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int8_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    int8_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    int8_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int8_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int8_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    int8_t cast(object value)
//    {
//        return value.get_as<int64_t>();
//    }
//
////  uint8_t ----------------------------------------------------------------------
//
//    template<>
//    uint8_t cast(int64_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint8_t cast(int32_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint8_t cast(int16_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint8_t cast(int8_t value)
//    {
//        return value;
//    }
//
//    template<>
//    uint8_t cast(uint64_t value)
//    {
//        if (value & (1LL << 63) != 0LL)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint8_t cast(uint32_t value)
//    {
//        return static_cast<int32_t>(value);
//    }
//
//    template<>
//    uint8_t cast(uint16_t value)
//    {
//        return static_cast<int16_t>(value);
//    }
//
//    template<>
//    uint8_t cast(uint8_t value)
//    {
//        return static_cast<int8_t>(value);
//    }
//
//    template<>
//    uint8_t cast(double value)
//    {
//        if (value < static_cast<double>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<double>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint8_t cast(float value)
//    {
//        if (value < static_cast<float>(std::numeric_limits<int64_t>::min())
//            || value > static_cast<float>(std::numeric_limits<int64_t>::max())
//            || static_cast<float>(static_cast<int64_t>(value)) - value > 1.0f)
//        {
//            /// TODO: exception
//        }
//        return static_cast<int64_t>(value);
//    }
//
//    template<>
//    uint8_t cast(bool value)
//    {
//        return value ? 1LL : 0LL;
//    }
//
//    template<>
//    uint8_t cast(text value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint8_t cast(char const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint8_t cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to integer
//    }
//
//    template<>
//    uint8_t cast(object value)
//    {
//        return value.get_as<int64_t>();
//    }
//
////  double -----------------------------------------------------------------------
//
//    template<>
//    double cast(int64_t value)
//    {
//        if (static_cast<int64_t>(static_cast<double>(value)) != value)
//        {
//            /// TODO: exception
//        }
//        return static_cast<double>(value);
//    }
//
//    template<>
//    double cast(int32_t value)
//    {
//        return cast<double>(static_cast<int64_t>(value));
//    }
//
//    template<>
//    double cast(int16_t value)
//    {
//        return cast<double>(static_cast<int64_t>(value));
//    }
//
//    template<>
//    double cast(int8_t value)
//    {
//        return cast<double>(static_cast<int64_t>(value));
//    }
//
//    template<>
//    double cast(uint64_t value)
//    {
//        if (static_cast<uint64_t>(static_cast<double>(value)) != value)
//        {
//            /// TODO: exception
//        }
//        return static_cast<double>(value);
//    }
//
//    template<>
//    double cast(uint32_t value)
//    {
//        return cast<double>(static_cast<uint64_t>(value));
//    }
//
//    template<>
//    double cast(uint16_t value)
//    {
//        return cast<double>(static_cast<uint64_t>(value));
//    }
//
//    template<>
//    double cast(uint8_t value)
//    {
//        return cast<double>(static_cast<uint64_t>(value));
//    }
//
//    template<>
//    double cast(double value)
//    {
//        return value;
//    }
//
//    template<>
//    double cast(float value)
//    {
//        return static_cast<double>(value);
//    }
//
//    template<>
//    double cast(bool value)
//    {
//        return value ? 1 : 0;
//    }
//
//    template<>
//    double cast(text value)
//    {
//        return 0; /// TODO: text to double
//    }
//
//    template<>
//    double cast(char const* value)
//    {
//        return 0; /// TODO: text to double
//    }
//
//    template<>
//    double cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to double
//    }
//
//    template<>
//    double cast(object value)
//    {
//        return value.get_as<double>();
//    }
//
////  float ------------------------------------------------------------------------
//
//    template<>
//    float cast(int64_t value)
//    {
//        if (static_cast<int64_t>(static_cast<double>(value)) != value)
//        {
//            /// TODO: exception
//        }
//        return static_cast<float>(value);
//    }
//
//    template<>
//    float cast(int32_t value)
//    {
//        return cast<float>(static_cast<int64_t>(value));
//    }
//
//    template<>
//    float cast(int16_t value)
//    {
//        return cast<float>(static_cast<int64_t>(value));
//    }
//
//    template<>
//    float cast(int8_t value)
//    {
//        return cast<float>(static_cast<int64_t>(value));
//    }
//
//    template<>
//    float cast(uint64_t value)
//    {
//        if (static_cast<uint64_t>(static_cast<double>(value)) != value)
//        {
//            /// TODO: exception
//        }
//        return static_cast<float>(value);
//    }
//
//    template<>
//    float cast(uint32_t value)
//    {
//        return cast<float>(static_cast<uint64_t>(value));
//    }
//
//    template<>
//    float cast(uint16_t value)
//    {
//        return cast<float>(static_cast<uint64_t>(value));
//    }
//
//    template<>
//    float cast(uint8_t value)
//    {
//        return cast<float>(static_cast<uint64_t>(value));
//    }
//
//    template<>
//    float cast(double value)
//    {
//        return value;
//    }
//
//    template<>
//    float cast(float value)
//    {
//        return static_cast<double>(value);
//    }
//
//    template<>
//    float cast(bool value)
//    {
//        return value ? 1 : 0;
//    }
//
//    template<>
//    float cast(text value)
//    {
//        return 0; /// TODO: text to double
//    }
//
//    template<>
//    float cast(char const* value)
//    {
//        return 0; /// TODO: text to double
//    }
//
//    template<>
//    float cast(wchar_t const* value)
//    {
//        return 0; /// TODO: text to double
//    }
//
//    template<>
//    float cast(object value)
//    {
//        return value.get_as<float>();
//    }
//
////  bool -------------------------------------------------------------------------
//
//    template<>
//    bool cast(int64_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(int32_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(int16_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(int8_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(uint64_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(uint32_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(uint16_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(uint8_t value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(double value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(float value)
//    {
//        return value != 0;
//    }
//
//    template<>
//    bool cast(bool value)
//    {
//        return value;
//    }
//
//    template<>
//    bool cast(text value)
//    {
//        return false; /// TODO: text to bool
//    }
//
//    template<>
//    bool cast(char const* value)
//    {
//        return false; /// TODO: text to bool
//    }
//
//    template<>
//    bool cast(wchar_t const* value)
//    {
//        return false; /// TODO: text to bool
//    }
//
//    template<>
//    bool cast(object value)
//    {
//        return value.get_as<bool>();
//    }
//
////  text -----------------------------------------------------------------------
//
//    template<>
//    text cast(int64_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(int32_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(int16_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(int8_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(uint64_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(uint32_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(uint16_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(uint8_t value)
//    {
//        return text(); /// TODO: integer to text
//    }
//
//    template<>
//    text cast(double value)
//    {
//        return text(); /// TODO: floating point value to text
//    }
//
//    template<>
//    text cast(float value)
//    {
//        return text(); /// TODO: floating point value to text
//    }
//
//    template<>
//    text cast(bool value)
//    {
//        return text(); /// TODO: bool to text
//    }
//
//    template<>
//    text cast(text value)
//    {
//        return value;
//    }
//
//    template<>
//    text cast(char const* value)
//    {
//        return text(); /// TODO: text to byte string
//    }
//
//    template<>
//    text cast(wchar_t const* value)
//    {
//        return text(); /// TODO: text to wide string
//    }
//
//    template<>
//    text cast(object value)
//    {
//        return value.get_as<text>();
//    }
}

// sine qua non
