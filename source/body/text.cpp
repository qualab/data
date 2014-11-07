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

    text::text(char const* value)
    {
        // TODO: initialization by byte-character C string
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

    text::text(std::string const& value, char const* encoding)
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

    text::text(bool value)
    {
        // TODO: convert boolean value to text
    }

    text::text(int64_t value)
    {
        // TODO: convert 64-bit signed integer to text
    }

    text::text(int32_t value)
    {
        // TODO: convert 32-bit signed integer value to text
    }

    text::text(int16_t value)
    {
        // TODO: convert 16-bit signed integer value to text
    }

    text::text(int8_t value)
    {
        // TODO: convert 8-bit signed integer value to text
    }

    text::text(uint64_t value)
    {
        // TODO: convert 64-bit unsigned integer value to text
    }

    text::text(uint32_t value)
    {
        // TODO: convert 32-bit unsigned integer value to text
    }

    text::text(uint16_t value)
    {
        // TODO: convert 16-bit unsigned integer value to text
    }

    text::text(uint8_t value)
    {
        // TODO: convert 8-bit unsigned integer value to text
    }

    text::text(double value)
    {
        // TODO: convert double-precision floating-point value to text
    }

    text::text(float value)
    {
        // TODO: convert double-precision floating-point value to text
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
