/// @author Владимир Керимов

#include <data_head/boolean_data.hpp>

namespace data
{
    boolean::data::data()
        : m_value()
    {
    }

    boolean::data::data(bool value)
        : m_value(value)
    {
    }

    bool boolean::data::is_null() const
    {
        return false;
    }
}

// sine qua non
