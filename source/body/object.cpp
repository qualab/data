/// @author Владимир Керимов

#include <data_head/object_data.hpp>
#include <data/text>
#include <data/trace>

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

#define DATA_OBJECT_DECLARE_CONSTRUCTOR(value_type, value_type_name) \
    object::object(value_type value) \
        : m_data(new(m_buffer) scalar_data<value_type>(value)) \
    { \
        static_assert(sizeof(scalar_data<value_type>) <= data_max_size, \
                      "Unable to inplace " ## value_type_name ## \
                      " object data into the buffer prepared. " \
                      "Not enough memory in buffer, data size is too big."); \
    }

    DATA_OBJECT_DECLARE_CONSTRUCTOR(bool,     "boolean")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(int8_t,   "8-bit signed integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(int16_t,  "16-bit signed integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(int32_t,  "32-bit signed integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(int64_t,  "64-bit signed integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(uint8_t,  "8-bit unsigned integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(uint16_t, "16-bit unsigned integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(uint32_t, "32-bit unsigned integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(uint64_t, "64-bit unsigned integer")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(float,    "single precision floating-point")
    DATA_OBJECT_DECLARE_CONSTRUCTOR(double,   "double precision floating-point")

    object::object(char const* value)
        : m_data(nullptr)
    {
        *this = text(value);
    }

    object::object(wchar_t const* value)
        : m_data(nullptr)
    {
        *this = text(value);
    }

    object::object(std::string const& value)
        : m_data(nullptr)
    {
        *this = text(value);
    }

    object::object(std::wstring const& value)
        : m_data(nullptr)
    {
        *this = text(value);
    }
}

// sine qua non
