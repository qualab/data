/// @author Владимир Керимов

#pragma once

#include <data_head/text_data.hpp>
#include <string>

namespace data
{
    typedef std::basic_string<int32_t> unicode_string;

    class text::data::body
    {
    public:
        body();
        body(char const* byte_string);
        body(char const* byte_string, char const* encoding);
        body(char const* byte_string, std::string const& encoding);
        body(std::string const& byte_string);
        body(std::string const& byte_string, char const* encoding);
        body(std::string const& byte_string, std::string const& encoding);
        body(wchar_t const* wide_string);
        body(std::wstring const& wide_string);

        body& operator = (char const* byte_string);
        body& operator = (std::string const& byte_string);
        body& operator = (wchar_t const* wide_string);
        body& operator = (std::wstring const& wide_string);

        std::string const& encoding() const;

        std::string const& byte_string() const;
        std::string const& byte_string(char const* encoding) const;
        std::string const& byte_string(std::string const& encoding) const;
        std::wstring const& wide_string() const;
        
        char const* byte_c_str() const;
        char const* byte_c_str(char const* encoding) const;
        char const* byte_c_str(std::string const& encoding) const;
        wchar_t const* wide_c_str() const;

    private:
        unicode_string m_unicode_string;
        std::wstring m_wide_string;
        std::string m_byte_string;
        std::string m_encoding;
    };
}

// sine qua non
