/// @author Владимир Керимов

#include <data/api>
#include <data/stdfwd>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace data
{
    class text;
    class object;

    template <typename result_type, typename value_type>
    bool try_cast(result_type& result, value_type const& value);

    template <typename result_same_type>
    bool try_cast(result_same_type& result, result_same_type const& value)
    {
        result = value;
        return true;
    }

    template <typename result_type, typename value_type>
    bool try_cast< typename std::enable_if<std::is_integral<result_type>::value &&
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
                   result_type>::type, value_type >(result_type& result, value_type value)
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
    result_type cast(value_type value);

    template <typename result_same_type>
    result_same_type cast(result_same_type value)
    {
        return value;
    }

    DATA_API void unable_to_cast(char const* result_type_name, char const* value_type_name);

    template <typename result_type, typename value_type>
    result_type cast(value_type value)
    {
        result_type result;
        if (!try_cast(result, value))
            unable_to_cast(typeid(result_type).name(), typeid(value_type).name());
        return static_cast<result_type>(value);
    }
}

// sine qua non
