/// @author Владимир Керимов

#include "text_data.hpp"

namespace data
{
    text::data::data()
        : m_value()
    {
    }

    text::data::data(unicode_string const& value)
        : m_value(value)
    {
    }

    bool text::data::is_null() const
    {
        return false;
    }
}

// sine qua non
