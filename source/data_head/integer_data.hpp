/// @author Владимир Керимов

#pragma once

#include <data/integer>
#include <data_head/object_data.hpp>

namespace data
{
    class integer::data : public object::data
    {
    public:
        data();
        data(int64_t value);
        virtual bool is_null() const override;
        int64_t get_value() const;

    private:
        int64_t m_value;
    };
}

// sine qua non
