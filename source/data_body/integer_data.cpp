/// @author Владимир Керимов

#include <data_head/integer_data.hpp>

namespace data
{
    integer::data::data()
        : m_value()
    {
    }

    integer::data::data(int64_t value)
        : m_value(value)
    {
    }

    bool integer::data::is_null() const
    {
        return false;
    }

    int64_t integer::data::get_value() const
    {
        return m_value;
    }

    int64_t integer::data::get_as_int64() const
    {
        return get_value();
    }

    bool integer::data::get_as_bool() const
    {
        return cast<bool>(get_value());
    }
}

// sine qua non
