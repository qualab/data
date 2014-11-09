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
        data(std::string const& byte_string);
        data(std::string const& byte_string, std::string const& encoding);
        data(std::wstring const& wide_string);

        data& operator = (std::string const& byte_string);
        data& operator = (std::pair<std::string, std::string> const& string_encoded);
        data& operator = (std::wstring const& wide_string);

        std::string encoding() const;
        std::string as_byte_string() const;
        std::wstring as_wide_string() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    protected:
        class body;

    private:
        lazy_data<body> m_body;
    };
}

// sine qua non
