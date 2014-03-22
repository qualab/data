/// @author Владимир Керимов

#include "object_data.hpp"

namespace data
{
    // Creation of null-object
    object::object()
    {
    }

    // Base virtual destructor
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
        return true;
    }

    object::object(lazy<object::data> const& data)
        : m_data(data)
    {
    }
}

// sine qua non
