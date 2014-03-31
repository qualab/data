/// @author Владимир Керимов

#include "integer_data.hpp"

namespace data
{
    integer::integer()
    {
    }

    object integer::clone() const
    {
        return object(m_data.clone_as<object::data>());
    }

    integer::integer(integer::data* new_data)
        : m_data(new_data)
    {
    }

    template<>
    void object::set_as(int64_t value)
    {
        m_data = lazy<object::data>(new integer::data(value));
    }

    template<>
    void object::set_as(int32_t value)
    {
        m_data = lazy<object::data>(new integer::data(value));
    }

    template<>
    void object::set_as(int16_t value)
    {
        m_data = lazy<object::data>(new integer::data(value));
    }

    template<>
    void object::set_as(int8_t value)
    {
        m_data = lazy<object::data>(new integer::data(value));
    }

    template<>
    void object::set_as(uint64_t value)
    {
        m_data = lazy<object::data>(new integer::data(static_cast<int64_t>(value)));
    }

    template<>
    void object::set_as(uint32_t value)
    {
        m_data = lazy<object::data>(new integer::data(static_cast<int32_t>(value)));
    }

    template<>
    void object::set_as(uint16_t value)
    {
        m_data = lazy<object::data>(new integer::data(static_cast<int16_t>(value)));
    }

    template<>
    void object::set_as(uint8_t value)
    {
        m_data = lazy<object::data>(new integer::data(static_cast<int8_t>(value)));
    }
}

// sine qua non
