/// @author Владимир Керимов

#include <data/text>
#include <data/decimal>
#include <data/exception>
#include <type_traits>
#include <typeinfo>
#include <cstdint>
#include <limits>

namespace data
{
    /// Special structure to implement common functionality for type cast of scalar data
    template <typename result_type, typename value_type, typename meta_type = void>
    struct type_cast
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            static_assert(false, "Type cast is not enabled between two types specified.");
        }
    };

    /// Try to cast value of value_type to the result_type and returns true if success and false otherwise
    template <typename result_type, typename value_type>
    bool try_cast(result_type& result, value_type const& value) noexcept
    {
        return type_cast<result_type, value_type>::try_cast(result, value);
    }

    /// Cast value of value_type to the result_type and throw exception if failure
    template <typename result_type, typename value_type>
    result_type cast(value_type const& value)
    {
        result_type result;
        if (!try_cast(result, value))
            DATA_EXCEPTION_THROW(nonexistent_type_cast, "No type cast exists between the types specified.");
        return result;
    }

    // Specializations of template of type_cast

    // Trevial cast to the same type
    template <typename same_type>
    struct type_cast<same_type, same_type>
    {
        static bool try_cast(same_type& result, same_type const& value) noexcept
        {
            result = value;
            return true;
        }
    };

    // Cast arithmetic value to boolean type
    template <typename value_type>
    struct type_cast<bool, value_type,
                       typename std::enable_if<!std::is_same<bool, value_type>::value &&
                                                std::is_arithmetic<value_type>::value>::type>
    {
        static bool try_cast(bool& result, value_type const& value) noexcept
        {
            result = (value != 0);
            return true;
        }
    };

    // Cast boolean value to arithmetic type
    template <typename result_type>
    struct type_cast<result_type, bool,
                       typename std::enable_if<!std::is_same<result_type, bool>::value &&
                                               (std::is_arithmetic<result_type>::value ||
                                                std::is_same<result_type, decimal>::value)>::type>
    {
        static bool try_cast(result_type& result, bool const& value) noexcept
        {
            result = value ? result_type(1) : result_type(0);
            return true;
        }
    };

    // Cast integral value to integral of greater size with same signed attribute
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                               (std::is_signed<result_type>::value == std::is_signed<value_type>::value) &&
                                               (sizeof(result_type) >= sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            result = value;
            return true;
        }
    };

    // Cast unsigned integer to the unsigned integral type of less size
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                                std::is_unsigned<result_type>::value &&
                                                std::is_unsigned<value_type>::value &&
                                               (sizeof(result_type) < sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            if ((value & std::numeric_limits<result_type>::max()) != value)
                return false;
            result = result_type(value);
            return true;
        }
    };

    // Cast signed integer to the signed integral type of less size
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                                std::is_signed<result_type>::value &&
                                                std::is_signed<value_type>::value &&
                                               (sizeof(result_type) < sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            if ((value & (std::numeric_limits<result_type>::max() | std::numeric_limits<value_type>::min())) != value)
            {
                return false;
            }
            result = result_type(value);
            return true;
        }
    };

    // Cast signed integer to the unsigned integral type
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                                std::is_unsigned<result_type>::value &&
                                                std::is_signed<value_type>::value &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            if (value < 0)
                return false;
            return type_cast<result_type,
                             typename std::make_unsigned<value_type>::type
                             >::try_cast(result, value);
        }
    };

    // Cast unsigned integer to the signed integral type of greater size
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                                std::is_signed<result_type>::value &&
                                                std::is_unsigned<value_type>::value &&
                                               (sizeof(result_type) > sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            result = static_cast<typename std::make_signed<value_type>::type>(value);
            return true;
        }
    };

    // Cast unsigned integer to the signed integral type of less or equal size
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                                std::is_signed<result_type>::value &&
                                                std::is_unsigned<value_type>::value &&
                                               (sizeof(result_type) <= sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            if ((value & std::numeric_limits<result_type>::min()) != 0 ||   // bit of sign is set
                 value > static_cast<typename std::make_unsigned<result_type>::type>(
                                std::numeric_limits<result_type>::max()))   // value is greater than maximum
            {
                return false;
            }
            result = static_cast<result_type>(
                        static_cast<typename std::make_signed<value_type>::type>(value));
            return true;
        }
    };

    // Cast value of arithmetic type into the floating-point type
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_floating_point<result_type>::value &&
                                                std::is_arithmetic<value_type>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            if (result_type(value) < -std::numeric_limits<result_type>::max() ||
                result_type(value) >  std::numeric_limits<result_type>::max())
            {
                return false;
            }
            result = result_type(value);
            return true;
        }
    };

    // Cast value of arithmetic type into the floating-point type
    template <typename result_type, typename value_type>
    struct type_cast<result_type, value_type,
                        typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                 std::is_integral<result_type>::value &&
                                                 std::is_floating_point<value_type>::value &&
                                                !std::is_same<result_type, bool>::value &&
                                                !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value) noexcept
        {
            if (value < value_type(std::numeric_limits<result_type>::min()) ||
                value > value_type(std::numeric_limits<result_type>::max()))
            {
                return false;
            }
            result = result_type(value);
            return true;
        }
    };

    // Cast boolean value to textual type
    template <typename value_type>
    struct type_cast<text, value_type>
    {
        static bool try_cast(text& result, value_type const& value) noexcept
        {
            result = text(value);
            return true;
        }
    };

    template <typename value_type>
    struct type_cast<decimal, value_type,
                        typename std::enable_if<!std::is_same<decimal, value_type>::value &&
                                                 std::is_arithmetic<value_type>::value &&
                                                !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(decimal& result, value_type const& value) noexcept
        {
            result = decimal(value);
            return true;
        }
    };

    template <>
    struct DATA_API type_cast<std::string, int64_t>
    {
        static bool try_cast(std::string& result, int64_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, int32_t>
    {
        static bool try_cast(std::string& result, int32_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, int16_t>
    {
        static bool try_cast(std::string& result, int16_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, int8_t>
    {
        static bool try_cast(std::string& result, int8_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, uint64_t>
    {
        static bool try_cast(std::string& result, uint64_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, uint32_t>
    {
        static bool try_cast(std::string& result, uint32_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, uint16_t>
    {
        static bool try_cast(std::string& result, uint16_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, uint8_t>
    {
        static bool try_cast(std::string& result, uint8_t const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, double>
    {
        static bool try_cast(std::string& result, double const& value);
    };

    template <>
    struct DATA_API type_cast<std::string, float>
    {
        static bool try_cast(std::string& result, float const& value);
    };

    template <>
    struct DATA_API type_cast<int64_t, std::string>
    {
        static bool try_cast(int64_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<int32_t, std::string>
    {
        static bool try_cast(int32_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<int16_t, std::string>
    {
        static bool try_cast(int16_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<int8_t, std::string>
    {
        static bool try_cast(int8_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<uint64_t, std::string>
    {
        static bool try_cast(uint64_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<uint32_t, std::string>
    {
        static bool try_cast(uint32_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<uint16_t, std::string>
    {
        static bool try_cast(uint16_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<uint8_t, std::string>
    {
        static bool try_cast(uint8_t& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<double, std::string>
    {
        static bool try_cast(double& result, std::string const& value);
    };

    template <>
    struct DATA_API type_cast<float, std::string>
    {
        static bool try_cast(float& result, std::string const& value);
    };
}

// sine qua non
