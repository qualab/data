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

    double floating::data::get_value() const
    {
        return m_value;
    }

    double floating::data::get_as_double() const
    {
        return get_value();
    }

    bool floating::data::get_as_bool() const
    {
        return cast<bool>(get_value());
    }
}

// sine qua non
