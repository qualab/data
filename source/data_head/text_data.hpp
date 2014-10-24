/// @author Владимир Керимов

#pragma once

#include <data/text>
#include <data_head/object_data.hpp>
#include <string>

namespace data
{
    typedef std::basic_string<int32_t> unicode_string;

    class text::data : public object::data
    {
    public:
        data();
        data(unicode_string const& value);

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        unicode_string m_value;
    };
}

// sine qua non
