/// @author Владимир Керимов

#include <data_head/boolean_data.hpp>

namespace data
{
    boolean::boolean()
    {
    }

    template<>
    void object::set_as(bool value)
    {
        m_data.reset(new lazy<object::data>(new boolean::data(value)));
    }
}

// sine qua non
