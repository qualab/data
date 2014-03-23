/// @author Владимир Керимов

#include "boolean_data.hpp"

namespace data
{
    boolean::boolean()
    {
    }

    object boolean::clone() const
    {
        return object(m_data.clone());
    }
}

// sine qua non
