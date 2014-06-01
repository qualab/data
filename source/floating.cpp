/// @author Владимир Керимов

#include "floating_data.hpp"

namespace data
{
    floating::floating()
    {
    }

    template<>
    void object::set_as(double value)
    {
        m_data.reset(new lazy<object::data>(new floating::data(value)));
    }

    template<>
    void object::set_as(float value)
    {
        m_data.reset(new lazy<object::data>(new floating::data(value)));
    }
}

// sine qua non
