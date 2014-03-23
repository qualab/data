/// @author Владимир Керимов

#pragma once

#include <data/floating>
#include "object_data.hpp"

namespace data
{
    class floating::data : public object::data
    {
    public:
        data();
        data(double value);
        virtual bool is_null() const;
    private:
        double m_value;
    };
}

// sine qua non
