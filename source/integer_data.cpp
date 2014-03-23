/// @author Владимир Керимов

#include "integer_data.hpp"

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
}

// sine qua non
