/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/stdfwd>

namespace data
{
    /// Type for textual data
    class DATA_API text : public object
    {
    public:
        /// Create null-object of no text
        text();

        text(char const* value, char const* encoding = nullptr);
        text(wchar_t const* value);
        text(std::string const& value, std::string const& encoding);
        text(std::string const& value);
        text(std::wstring const& value);

        text(object const& another);

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
