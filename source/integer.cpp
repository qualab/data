/// @author Владимир Керимов

#include "integer_data.hpp"

namespace data
{
    integer::integer()
    {
    }

    object integer::clone() const
    {
        return object(m_data.clone());
    }

    integer::integer(integer::data* new_data)
        : m_data(new_data)
    {
    }
}

// sine qua non
