/// @author Владимир Керимов

#include <data_head/text_data.hpp>

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
}

// sine qua non
