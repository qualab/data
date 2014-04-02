/// @author Владимир Керимов

#include "boolean_data.hpp"

namespace data
{
    boolean::boolean()
    {
    }

    template<>
    void object::set_as(bool value)
    {
        m_data = lazy<object::data>(new boolean::data(value));
    }
}

// sine qua non
