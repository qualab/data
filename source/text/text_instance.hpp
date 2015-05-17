/// @author Владимир Керимов

#pragma once

#include <data/text>

namespace data
{
    class text::instance
    {
    public:
        instance();
        instance(char const* byte_string);
        instance(char const* byte_string, char const* encoding);
        instance(char const* byte_string, std::string const& encoding);
        instance(std::string const& byte_string);
        instance(std::string const& byte_string, char const* encoding);
        instance(std::string const& byte_string, std::string const& encoding);
        instance(wchar_t const* wide_string);
        instance(std::wstring const& wide_string);

        instance& operator = (char const* byte_string);
        instance& operator = (std::string const& byte_string);
        instance& operator = (wchar_t const* wide_string);
        instance& operator = (std::wstring const& wide_string);

        std::string const& encoding() const;

        std::string const& byte_string() const;
        std::string const& byte_string(char const* encoding) const;
        std::string const& byte_string(std::string const& encoding) const;
        std::wstring const& wide_string() const;
        
        char const* byte_c_str() const;
        char const* byte_c_str(char const* encoding) const;
        char const* byte_c_str(std::string const& encoding) const;
        wchar_t const* wide_c_str() const;

        //bool as_bool() const;
        //
        //int64_t as_int64() const;
        //int32_t as_int32() const;
        //int16_t as_int16() const;
        //int8_t  as_int8()  const;

        //uint64_t as_uint64() const;
        //uint32_t as_uint32() const;
        //uint16_t as_uint16() const;
        //uint8_t  as_uint8()  const;

        //double as_double() const;
        //float  as_float()  const;

        //decimal as_decimal() const;

        template <typename value_type>
        value_type as() const;

    private:
        unicode_string m_unicode_string;
        std::wstring m_wide_string;
        std::string m_byte_string;
        std::string m_encoding;
    };

    template <typename value_type>
    value_type text::data::body::as() const
    {
        if (!m_byte_string.empty())
            return cast<value_type>(m_byte_string);
        else if (!m_wide_string.empty())
            return cast<value_type>(m_wide_string);
        else
            return cast<value_type>(byte_string());
    }
}

// sine qua non
