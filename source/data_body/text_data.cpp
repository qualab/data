/// @author Владимир Керимов

#include <data_head/text_data_body.hpp>
#include <data/decimal>

namespace data
{
    text::data::data()
    {
    }

    text::data::data(char const* byte_string)
        : m_body(new body(byte_string))
    {
    }

    text::data::data(char const* byte_string, char const* encoding)
        : m_body(new body(byte_string, encoding))
    {
    }

    text::data::data(char const* byte_string, std::string const& encoding)
        : m_body(new body(byte_string, encoding))
    {
    }

    text::data::data(std::string const& byte_string)
        : m_body(new body(byte_string))
    {
    }

    text::data::data(std::string const& byte_string, char const* encoding)
        : m_body(new body(byte_string, encoding))
    {
    }

    text::data::data(std::string const& byte_string, std::string const& encoding)
        : m_body(new body(byte_string, encoding))
    {
    }

    text::data::data(wchar_t const* wide_string)
        : m_body(new body(wide_string))
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

    std::string const& text::data::byte_string() const
    {
        return m_body->byte_string();
    }

    std::string const& text::data::byte_string(char const* encoding) const
    {
        return m_body->byte_string(encoding);
    }

    std::string const& text::data::byte_string(std::string const& encoding) const
    {
        return m_body->byte_string(encoding);
    }

    std::wstring const& text::data::wide_string() const
    {
        return m_body->wide_string();
    }

    char const* text::data::byte_c_str() const
    {
        return m_body->byte_c_str();
    }

    char const* text::data::byte_c_str(char const* encoding) const
    {
        return m_body->byte_c_str(encoding);
    }

    char const* text::data::byte_c_str(std::string const& encoding) const
    {
        return m_body->byte_c_str(encoding);
    }

    wchar_t const* text::data::wide_c_str() const
    {
        return m_body->wide_c_str();
    }

    bool text::data::as_bool() const
    {
        return m_body->as<bool>();
    }

    int64_t text::data::as_int64() const
    {
        return m_body->as<int64_t>();
    }

    int32_t text::data::as_int32() const
    {
        return m_body->as<int32_t>();
    }

    int16_t text::data::as_int16() const
    {
        return m_body->as<int16_t>();
    }

    int8_t text::data::as_int8() const
    {
        return m_body->as<int8_t>();
    }

    uint64_t text::data::as_uint64() const
    {
        return m_body->as<uint64_t>();
    }

    uint32_t text::data::as_uint32() const
    {
        return m_body->as<uint32_t>();
    }

    uint16_t text::data::as_uint16() const
    {
        return m_body->as<uint16_t>();
    }

    uint8_t text::data::as_uint8() const
    {
        return m_body->as<uint8_t>();
    }

    double text::data::as_double() const
    {
        return m_body->as<double>();
    }

    float text::data::as_float() const
    {
        return m_body->as<float>();
    }

    decimal text::data::as_decimal() const
    {
        return m_body->as<decimal>();
    }
}

// sine qua non
