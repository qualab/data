/// @author Владимир Керимов

#include "floating_data.hpp"

namespace data
{
    floating::data::data()
        : m_value()
    {
    }

    floating::data::data(double value)
        : m_value(value)
    {
    }

    bool floating::data::is_null() const
    {
        return false;
    }
}

// sine qua non
