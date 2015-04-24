/// @author Владимир Керимов

#include <data_head/text_data_body.hpp>
#include <data/cast>

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

    //bool text::data::body::as_bool() const
    //{
    //    if (!m_byte_string.empty())
    //        return cast<bool>(m_byte_string);
    //    else if (!m_wide_string.empty())
    //        return cast<bool>(m_wide_string);
    //    else
    //        return cast<bool>(byte_string());
    //}

    //int64_t text::data::body::as_int64() const
    //{
    //}

    //int32_t text::data::body::as_int32() const
    //{
    //}

    //int16_t text::data::body::as_int16() const
    //{
    //}

    //int8_t text::data::body::as_int8() const
    //{
    //}

    //uint64_t text::data::body::as_uint64() const
    //{
    //}

    //uint32_t text::data::body::as_uint32() const
    //{
    //}

    //uint16_t text::data::body::as_uint16() const
    //{
    //}

    //uint8_t text::data::body::as_uint8() const
    //{
    //}

    //double text::data::body::as_double() const
    //{
    //}

    //float text::data::body::as_float() const
    //{
    //}

    //decimal text::data::body::as_decimal() const
    //{
    //}
}

// sine qua non
