/// @author Владимир Керимов

#include <data_head/text_data_body.hpp>

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
}

// sine qua non
