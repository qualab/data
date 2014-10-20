/// @author Владимир Керимов

#include <data_head/object_data.hpp>
#include <data/trace>
#include <data/cast>

namespace data
{
    const object null;

    object::object()
        : m_data(nullptr)
    {
    }

    object::~object()
    {
        destruct();
    }

    object::object(object const& another)
        : m_data(another.m_data->copy_to(m_buffer))
    {
    }

    object& object::operator = (object const& another)
    {
        destruct();
        m_data = another.m_data->copy_to(m_buffer);
        return *this;
    }

    object::object(object&& temporary)
        : m_data(temporary.m_data->move_to(m_buffer))
    {
    }

    object& object::operator = (object&& temporary)
    {
        destruct();
        m_data = temporary.m_data->move_to(m_buffer);
        return *this;
    }

    object object::clone() const
    {
        return m_data ? m_data->clone() : null;
    }

    bool object::is_null() const
    {
        return m_data == nullptr;
    }

    char* object::buffer()
    {
        return m_buffer;
    }

    object::object(object::data&& prepared_data)
        : m_data(prepared_data.move_to(m_buffer))
    {
    }

    object::object(std::nullptr_t)
        : m_data(nullptr)
    {
    }

    object::object(bool value)
        : m_data(new(m_buffer) scalar_data<bool>(value))
    {
        static_assert(sizeof(scalar_data<bool>) <= data_max_size, "Unable to inplace boolean object data into the buffer prepared. Not enough memory in buffer, data size is too big.");
    }

    object::object(int8_t value)
        : m_data(new(m_buffer) scalar_data<int8_t>(value))
    {
        static_assert(sizeof(scalar_data<bool>) <= data_max_size, "Unable to inplace object data of 8-bit signed integer into the buffer prepared. Not enough memory in buffer, data size is too big.");
    }
}

// sine qua non
