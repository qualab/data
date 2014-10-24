/// @author Владимир Керимов

#include <data_head/text_data.hpp>
#include <data/exception>
#include <string>

namespace data
{
    // Creation of null-object
    text::text()
    {
    }

    text::text(char const* value, char const* encoding)
    {
        // TODO: initialization by byte-character C string
    }

    text::text(wchar_t const* value)
    {
        // TODO: initialization by wide-character C string
    }

    text::text(std::string const& value, std::string const& encoding)
    {
        // TODO: initialization by byte-character string container
    }

    text::text(std::string const& value)
    {
        // TODO: initialization by byte-character string container
    }

    text::text(std::wstring const& value)
    {
        // TODO: initialization by wide-character string container
    }

    text::text(object const& another)
        : object((m_data = new(buffer()) text::data(*dynamic_cast<text::data const*>(another.data_ptr()))))
    {
    }

    char const* text::byte_char(char const* encoding) const
    {
        return "";
    }

    wchar_t const* text::wide_char() const
    {
        return L"";
    }

    std::string text::byte_string(std::string const& encoding) const
    {
        return std::string();
    }

    std::string text::byte_string() const
    {
        return std::string();
    }

    std::wstring text::wide_string() const
    {
        return std::wstring();
    }
}

// sine qua non
