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
    class text;
    class object;

    template <typename result_type, typename value_type, typename meta_type = void>
    struct scalar_cast
    {
        static bool try_cast(result_type& result, value_type const& value)
        {
            static_assert(false, "Type cast is not enabled between two types specified.");
        }
    };

    template <typename result_type, typename value_type>
    bool try_cast(result_type& result, value_type const& value)
    {
        return scalar_cast<result_type, value_type>::try_cast(result, value);
    }

    template <typename result_type, typename value_type>
    result_type cast(value_type const& value)
    {
        result_type result;
        if (!try_cast(result, value))
            DATA_EXCEPTION_THROW(exception, "TODO: ...");
        return result;
    }

    // Specializations of template of scalar_cast

    template <typename same_type>
    struct scalar_cast<same_type, same_type>
    {
        static bool try_cast(same_type& result, same_type const& value)
        {
            result = value;
            return true;
        }
    };

    template <typename value_type>
    struct scalar_cast<bool, value_type,
                       typename std::enable_if<!std::is_same<bool, value_type>::value &&
                                                std::is_arithmetic<value_type>::value>::type>
    {
        static bool try_cast(bool& result, value_type const& value)
        {
            result = (value != 0);
            return true;
        }
    };

    template <typename result_type>
    struct scalar_cast<result_type, bool,
                       typename std::enable_if<!std::is_same<result_type, bool>::value &&
                                               (std::is_arithmetic<result_type>::value ||
                                                std::is_same<result_type, decimal>::value)>::type>
    {
        static bool try_cast(result_type& result, bool const& value)
        {
            result = value ? result_type(1) : result_type(0);
            return true;
        }
    };

    template <typename result_type, typename value_type>
    struct scalar_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                               (std::is_signed<result_type>::value == std::is_signed<value_type>::value) &&
                                               (sizeof(result_type) >= sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value)
        {
            result = value;
            return true;
        }
    };

    template <typename result_type, typename value_type>
    struct scalar_cast<result_type, value_type,
                       typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                                std::is_integral<result_type>::value &&
                                                std::is_integral<value_type>::value &&
                                               (std::is_signed<result_type>::value == std::is_signed<value_type>::value) &&
                                               (sizeof(result_type) < sizeof(value_type)) &&
                                               !std::is_same<result_type, bool>::value &&
                                               !std::is_same<value_type, bool>::value>::type>
    {
        static bool try_cast(result_type& result, value_type const& value)
        {
            result = value;
            return true;
        }
    };

    template <>
    struct scalar_cast<text, bool>
    {
        static bool try_cast(text& result, bool const& value)
        {
            result = value ? text("true") : text("false");
        }
    };
}

// sine qua non
