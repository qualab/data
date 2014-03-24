/// @author Владимир Керимов

#include "object_data.hpp"
#include "boolean_data.hpp"
#include "floating_data.hpp"
#include "integer_data.hpp"
#include "text_data.hpp"

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

    object::object(lazy<object::data> prepared_data)
        : m_data(prepared_data)
    {
    }
}

// sine qua non
