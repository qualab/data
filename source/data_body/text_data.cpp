/// @author Владимир Керимов

#include <data_head/text_data_body.hpp>

namespace data
{
    text::data::data()
    {
    }

    text::data::data(std::string const& byte_string)
        : m_body(new body(byte_string))
    {
    }

    text::data::data(std::string const& byte_string, std::string const& encoding)
        : m_body(new body(byte_string, encoding))
    {
    }

    text::data::data(std::wstring const& wide_string)
        : m_body(new body(wide_string))
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
