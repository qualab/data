/// @author Владимир Керимов

#include "floating_data.hpp"

namespace data
{
    floating::floating()
    {
    }

    object floating::clone() const
    {
        return object(m_data.clone());
    }

    floating::floating(floating::data* new_data)
        : m_data(new_data)
    {
    }
}

// sine qua non
