/// @author Владимир Керимов

#include "object_data.hpp"

namespace data
{
    object::object()
    {
    }

    object::~object()
    {
    }

    object::object(object const& another)
        : m_data(another.m_data)
    {
    }

    object object::clone() const
    {
        return object(m_data.clone());
    }

    bool object::is_null() const
    {
        return m_data->is_null();
    }

    object::object(object::data* new_data)
        : m_data(new_data)
    {
    }
}

// sine qua non
