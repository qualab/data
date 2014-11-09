/// @author Владимир Керимов

#include <data_head/text_data_body.hpp>

namespace data
{
    text::data::body::body()
    {
    }

    text::data::body::body(std::string const& byte_string)
        : m_byte_string(byte_string)
    {
    }

    text::data::body::body(std::string const& byte_string, std::string const& encoding)
        : m_byte_string(byte_string), m_encoding(encoding)
    {
    }

    text::data::body::body(std::wstring const& wide_string)
        : m_wide_string(wide_string)
    {
    }

    std::string text::data::body::as_byte_string() const
    {
        return m_byte_string;
    }

    std::wstring text::data::body::as_wide_string() const
    {
        return m_wide_string;
    }

    std::string text::data::body::encoding() const
    {
        return m_encoding;
    }
}

// sine qua non
