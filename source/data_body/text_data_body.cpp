/// @author Владимир Керимов

#include <data_head/text_data_body.hpp>

namespace data
{
    text::data::body::body()
    {
    }

    text::data::body::body(char const* byte_string)
        : m_byte_string(byte_string)
    {
    }

    text::data::body::body(char const* byte_string, char const* encoding)
        : m_byte_string(byte_string), m_encoding(encoding)
    {
    }

    text::data::body::body(char const* byte_string, std::string const& encoding)
        : m_byte_string(byte_string), m_encoding(encoding)
    {
    }

    text::data::body::body(wchar_t const* wide_string)
        : m_wide_string(wide_string)
    {
    }

    text::data::body::body(std::string const& byte_string)
        : m_byte_string(byte_string)
    {
    }

    text::data::body::body(std::string const& byte_string, char const* encoding)
        : m_byte_string(byte_string), m_encoding(encoding)
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

    std::string const& text::data::body::byte_string() const
    {
        return m_byte_string;
    }

    std::string const& text::data::body::byte_string(char const* encoding) const
    {
        return m_byte_string;
    }

    std::string const& text::data::body::byte_string(std::string const& encoding) const
    {
        return m_byte_string;
    }

    std::wstring const& text::data::body::wide_string() const
    {
        return m_wide_string;
    }

    std::string const& text::data::body::encoding() const
    {
        return m_encoding;
    }

    char const* text::data::body::byte_c_str() const
    {
        return m_byte_string.c_str();
    }

    char const* text::data::body::byte_c_str(char const* encoding) const
    {
        return m_byte_string.c_str();
    }

    char const* text::data::body::byte_c_str(std::string const& encoding) const
    {
        return m_byte_string.c_str();
    }

    wchar_t const* text::data::body::wide_c_str() const
    {
        return m_wide_string.c_str();
    }
}

// sine qua non
