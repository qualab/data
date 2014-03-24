/// @author Владимир Керимов

#include "boolean_data.hpp"

namespace data
{
    boolean::boolean()
    {
    }

    object boolean::clone() const
    {
        return object(m_data.clone_as<object::data>());
    }

    template<>
    void object::set_as(bool value)
    {
        m_data = lazy<object::data>(new boolean::data(value));
    }
}

// sine qua non
