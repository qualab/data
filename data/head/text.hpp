/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for textual data
    class DATA_API text : public object
    {
    public:
        /// Create null-object of no text
        text();

        /// Create text by byte-string with encoding specified
        text(char const* value, char const* encoding);

        /// Create text by byte-string without encoding specified
        text(char const* value);

        /// Create text by wide-string
        text(wchar_t const* value);

        /// Create text by byte-string with encoding specified
        text(std::string const& value, std::string const& encoding);

        /// Create text by byte-string with encoding specified
        text(std::string const& value, char const* encoding);

        /// Create text by byte-string without encoding specified
        text(std::string const& value);

        /// Create text by wide-string
        text(std::wstring const& value);

        /// Create text by another object
        text(object const& another);

        /// Type cast of boolean value to the text
        explicit text(bool value);

        /// Type cast of 64-bit signed integral value to the text
        explicit text(int64_t value);

        /// Type cast of 32-bit signed integral value to the text
        explicit text(int32_t value);

        /// Type cast of 16-bit signed integral value to the text
        explicit text(int16_t value);

        /// Type cast of 8-bit signed integral value to the text
        explicit text(int8_t  value);

        /// Type cast of 64-bit unsigned integral value to the text
        explicit text(uint64_t value);

        /// Type cast of 32-bit unsigned integral value to the text
        explicit text(uint32_t value);

        /// Type cast of 16-bit unsigned integral value to the text
        explicit text(uint16_t value);

        /// Type cast of 8-bit unsigned integral value to the text
        explicit text(uint8_t  value);

        /// Type cast of double-precision floating-point value to the text
        explicit text(double value);

        /// Type cast of single-precision floating-point value to the text
        explicit text(float  value);

        /// Get text as byte-character standard string container using encoding specified
        std::string const& byte_string(char const* encoding) const;

        /// Get text as byte-character standard string container using encoding specified
        std::string const& byte_string(std::string const& encoding) const;

        /// Get text as byte-character standard string container using default encoding
        std::string const& byte_string() const;

        /// Get text as wide-character standard string container
        std::wstring const& wide_string() const;

        /// Get text as pointer to byte-character null-terminated string using encoding specified
        char const* byte_c_str(char const* encoding) const;

        /// Get text as pointer to byte-character null-terminated string using encoding specified
        char const* byte_c_str(std::string const& encoding) const;

        /// Get text as pointer to byte-character null-terminated string using default encoding
        char const* byte_c_str() const;

        /// Get text as pointer to wide-character null-terminated string
        wchar_t const* wide_c_str() const;

    protected:
        /// Forward declaration of text::data
        class data;

    private:
        /// Stored pointer to text::data
        data* m_data;
    };
}

// sine qua non
