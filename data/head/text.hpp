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

        text(char const* value, char const* encoding);
        text(char const* value);
        text(wchar_t const* value);
        text(std::string const& value, std::string const& encoding);
        text(std::string const& value, char const* encoding);
        text(std::string const& value);
        text(std::wstring const& value);

        text(object const& another);

        explicit text(bool value);

        explicit text(int64_t value);
        explicit text(int32_t value);
        explicit text(int16_t value);
        explicit text(int8_t  value);

        explicit text(uint64_t value);
        explicit text(uint32_t value);
        explicit text(uint16_t value);
        explicit text(uint8_t  value);

        explicit text(double value);
        explicit text(float  value);

        char const* byte_char(char const* encoding = nullptr) const;
        wchar_t const* wide_char() const;

        std::string byte_string(std::string const& encoding) const;
        std::string byte_string() const;
        std::wstring wide_string() const;

    protected:
        /// Forward declaration of text::data
        class data;

    private:
        data* m_data;
    };
}

// sine qua non
