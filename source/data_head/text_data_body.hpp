/// @author Владимир Керимов

#pragma once

#include <data_head/text_data.hpp>
#include <string>

namespace data
{
    class text::data::body
    {
    public:
        body();
        body(std::string const& byte_string);
        body(std::string const& byte_string, std::string const& encoding);
        body(std::wstring const& wide_string);

        body& operator = (std::string const& byte_string);
        body& operator = (std::pair<std::string, std::string> const& string_encoded);
        body& operator = (std::wstring const& wide_string);

        std::string as_byte_string() const;
        std::wstring as_wide_string() const;
        std::string encoding() const;

    private:
        std::wstring m_wide_string;
        std::string m_byte_string;
        std::string m_encoding;
    };
}

// sine qua non
