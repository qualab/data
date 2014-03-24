/// @author Владимир Керимов

#include "floating_data.hpp"

namespace data
{
    floating::floating()
    {
    }

    object floating::clone() const
    {
        return object(m_data.clone_as<object::data>());
    }

    floating::floating(floating::data* new_data)
        : m_data(new_data)
    {
    }

    template<>
    void object::set_as(double value)
    {
        m_data = lazy<object::data>(new floating::data(value));
    }

    template<>
    void object::set_as(float value)
    {
        m_data = lazy<object::data>(new floating::data(value));
    }
}

// sine qua non
