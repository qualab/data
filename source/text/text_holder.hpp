/// @author Владимир Керимов

#pragma once

#include <data/text>
#include <data_head/object_data.hpp>
#include <data_head/lazy_data.hpp>

namespace data
{
    class text::data : public object::data
    {
    public:
        data();
        data(char const* byte_string);
        data(char const* byte_string, char const* encoding);
        data(char const* byte_string, std::string const& encoding);
        data(std::string const& byte_string);
        data(std::string const& byte_string, char const* encoding);
        data(std::string const& byte_string, std::string const& encoding);
        data(wchar_t const* wide_string);
        data(std::wstring const& wide_string);

        data& operator = (char const* byte_string);
        data& operator = (std::string const& byte_string);
        data& operator = (std::wstring const& wide_string);

        std::string const& encoding() const;
        std::string const& byte_string(char const* encoding) const;
        std::string const& byte_string(std::string const& encoding) const;
        std::string const& byte_string() const;
        std::wstring const& wide_string() const;
        char const* byte_c_str(std::string const& encoding) const;
        char const* byte_c_str(char const* encoding) const;
        char const* byte_c_str() const;
        wchar_t const* wide_c_str() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

        virtual bool    as_bool()  const override;

        virtual int64_t as_int64() const override;
        virtual int32_t as_int32() const override;
        virtual int16_t as_int16() const override;
        virtual int8_t  as_int8()  const override;

        virtual uint64_t as_uint64() const override;
        virtual uint32_t as_uint32() const override;
        virtual uint16_t as_uint16() const override;
        virtual uint8_t  as_uint8()  const override;

        virtual double as_double() const override;
        virtual float  as_float()  const override;

        virtual decimal as_decimal() const override;

    protected:
        class body;

    private:
        lazy_data<body> m_body;
    };
}

// sine qua non
