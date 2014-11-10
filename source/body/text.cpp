/// @author Владимир Керимов

#include <data_head/text_data.hpp>
#include <data/exception>
#include <data/trace>
#include <string>

namespace data
{
    text::text()
        : object(m_data = new(buffer()) text::data)
    {
        DATA_CALL_INFO("Create an empty data::text object with text of zero length.");
        static_assert(sizeof(text::data) <= data_max_size, "Data size of data::text class have greater size than provided by base data::object class.");
    }

    text::text(char const* value)
        : object(m_data = new(buffer()) text::data(value))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character C string with default encoding.");
    }

    text::text(char const* value, char const* encoding)
        : object(m_data = new(buffer()) text::data(value, encoding))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character C string with the encoding specified.");
    }

    text::text(wchar_t const* value)
        : object(m_data = new(buffer()) text::data(value))
    {
        DATA_CALL_INFO("Create an empty data::text by wide-character C string.");
    }

    text::text(std::string const& value, std::string const& encoding)
        : object(m_data = new(buffer()) text::data(value, encoding))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character string container with encoding specified by byte-character string container.");
    }

    text::text(std::string const& value, char const* encoding)
        : object(m_data = new(buffer()) text::data(value, encoding))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character string container with encoding specified by byte-character C string.");
    }

    text::text(std::string const& value)
        : object(m_data = new(buffer()) text::data(value))
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
