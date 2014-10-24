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

    object::data* text::data::copy_to(void* address) const
    {
        return new(address) text::data(*this);
    }

    object::data* text::data::move_to(void* address) const
    {
        return new(address) text::data(std::move(*this));
    }
}

// sine qua non
