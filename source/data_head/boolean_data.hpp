/// @author Владимир Керимов

#pragma once

#include <data/boolean>
#include <data_head/object_data.hpp>

namespace data
{
    class boolean::data : public object::data
    {
    public:
        data();
        data(bool value);
        virtual bool is_null() const;

    private:
        bool m_value;
    };
}

// sine qua non
