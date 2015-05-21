/// @author Владимир Керимов

#include <data/text>
#include <text/text_holder.hpp>
#include <data/exception>
#include <data/stacktrace>
#include <data/cast>
#include <string>

namespace data
{
    text::text()
    {
        DATA_CALL_INFO("Create an empty data::text object with text of zero length.");
        static_assert(sizeof(text::holder) <= object::max_holder_size, "Data size of data::text class have greater size than provided by base data::object class.");
    }

    text::text(char const* value)
        DATA_OBJECT_CREATE(text::holder, (value))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character C string with default encoding.");
    }

    text::text(char const* value, char const* encoding)
        DATA_OBJECT_CREATE(text::holder, (value, encoding))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character C string with the encoding specified.");
    }

    text::text(wchar_t const* value)
        DATA_OBJECT_CREATE(text::holder, (value))
    {
        DATA_CALL_INFO("Create an empty data::text by wide-character C string.");
    }

    text::text(std::string const& value, std::string const& encoding)
        DATA_OBJECT_CREATE(text::holder, (value, encoding))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character string container with encoding specified by byte-character string container.");
    }

    text::text(std::string const& value, char const* encoding)
        DATA_OBJECT_CREATE(text::holder, (value, encoding))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character string container with encoding specified by byte-character C string.");
    }

    text::text(std::string const& value)
        DATA_OBJECT_CREATE(text::holder, (value))
    {
        DATA_CALL_INFO("Create an empty data::text by byte-character string container with default encoding.");
    }

    text::text(std::wstring const& value)
        DATA_OBJECT_CREATE(text::holder, (value))
    {
        DATA_CALL_INFO("Create an empty data::text by wide-character string container.");
    }

    text::text(object const& another)
        DATA_OBJECT_CREATE(text::holder, (*dynamic_cast<text::holder const*>(another.data_ptr())))
    {
        DATA_CALL_INFO("Create data::text by another object.");
    }

    text::text(bool value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of boolean value.");
    }

    text::text(int64_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 64-bit signed integral value.");
    }

    text::text(int32_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 32-bit signed integral value.");
    }

    text::text(int16_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 16-bit signed integral value.");
    }

    text::text(int8_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 8-bit signed integral value.");
    }

    text::text(uint64_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 64-bit unsigned integral value.");
    }

    text::text(uint32_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 32-bit unsigned integral value.");
    }

    text::text(uint16_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 16-bit unsigned integral value.");
    }

    text::text(uint8_t value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of 8-bit unsigned integral value.");
    }

    text::text(double value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of double-precision floating-point value.");
    }

    text::text(float value)
        DATA_OBJECT_CREATE(text::holder, (cast<std::string>(value)))
    {
        DATA_CALL_INFO("Create data::text as representation of single-precision floating-point value.");
    }

    char const* text::byte_c_str(char const* encoding) const
    {
        DATA_CALL_INFO("Get text as pointer to byte-character null-terminated string "
                        "in encoding specified as pointer to byte-character null-terminated string.");
        return m_holder->byte_c_str(encoding);
    }

    char const* text::byte_c_str(std::string const& encoding) const
    {
        DATA_CALL_INFO("Get text as pointer to byte-character null-terminated string "
                        "in encoding specified as standard byte-character string container.");
        return m_holder->byte_c_str(encoding);
    }

    char const* text::byte_c_str() const
    {
        DATA_CALL_INFO("Get text as pointer to byte-character null-terminated string "
                        "in encoding specified inside data::text object.");
        return m_holder->byte_c_str();
    }

    wchar_t const* text::wide_c_str() const
    {
        DATA_CALL_INFO("Get pointer to wide-character null-terminated string.");
        return m_holder->wide_c_str();
    }

    std::string const& text::byte_string(std::string const& encoding) const
    {
        DATA_CALL_INFO("Get text as byte-character standard string container "
                        "in encoding specified as standard byte-character string container.");
        return m_holder->byte_string(encoding);
    }

    std::string const& text::byte_string() const
    {
        DATA_CALL_INFO("Get text as byte-character standard string container "
                        "in encoding specified inside data::text object.");
        return m_holder->byte_string();
    }

    std::wstring const& text::wide_string() const
    {
        DATA_CALL_INFO("Get text as wide-character standard string container.");
        return m_holder->wide_string();
    }
}

// sine qua non
