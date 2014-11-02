/// @author Владимир Керимов

#include <data/api>
#include <data/stdfwd>
#include <data/exception>
#include <type_traits>
#include <cstdint>
#include <limits>

namespace data
{
    class text;
    class object;

    template <typename result_type, typename value_type>
    bool try_cast(result_type& result, value_type const& value)
    {
        static_assert(false, "Not specialized try to cast from and into the types specified.");
    }

    template <typename result_type, typename value_type>
    bool try_cast<typename std::enable_if<std::is_same<result_type, value_type>::value,
                    result_type>::type, value_type>(result_type& result, value_type const& value)
    {
        result = value;
        return true;
    }

    template <typename result_type, typename value_type>
    bool try_cast< typename std::enable_if<!std::is_same<result_type, value_type>::value &&
                                           std::is_integral<result_type>::value &&
                                           std::is_integral<value_type>::value &&
                                           (std::is_signed<result_type>::value == std::is_signed<value_type>::value) &&
                                           (sizeof(result_type) >= sizeof(value_type)),
                   result_type>::type, value_type >(result_type& result, value_type const& value)
    {
        result = static_cast<result_type>(value);
        return true;
    }

    template <typename result_type, typename value_type>
    bool try_cast< typename std::enable_if<std::is_integral<result_type>::value &&
                                           std::is_integral<value_type>::value &&
                                           (std::is_signed<result_type>::value == std::is_signed<value_type>::value) &&
                                           (sizeof(result_type) < sizeof(value_type)),
                   result_type>::type, value_type >(result_type& result, value_type const& value)
    {
        if (value >= static_cast<value_type>(std::numeric_limits<result_type>::min()) &&
            value <= static_cast<value_type>(std::numeric_limits<result_type>::max()))
        {
            result = static_cast<result_type>(value);
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename result_type, typename value_type>
    result_type cast(value_type const& value)
    {
s        static_assert(false, "Not specialized cast from and into the types specifed.");
    }

    template <typename result_same_type>
    result_same_type cast(result_same_type const& value)
    {
        return value;
    }

    template <typename result_type, typename value_type>
    result_type cast<typename std::enable_if<!std::is_same<result_type, value_type>::value, result_type>::type, 
                     typename std::enable_if<!std::is_same<result_type, value_type>::value, value_type>::type>(value_type const& value)
    {
        result_type result;
        if (!try_cast<result_type, value_type>(result, value))
            DATA_EXCEPTION_THROW(exception, "TODO: ...");
        return static_cast<result_type>(value);
    }
}

// sine qua non
