﻿/// @author Владимир Керимов

#include <data_head/object_data.hpp>
#include <data_head/scalar_data.hpp>
#include <data/exception>
#include <data/decimal>
#include <data/text>
#include <data/trace>
#include <string>

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

    void object::destruct()
    {
        if (m_data)
            m_data->~data();
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
        if (!m_data)
        {
            return null;
        }
        else
        {
            object result;
            m_data->copy_to(result.m_buffer);
            return result;
        }
    }

    bool object::is_null() const
    {
        return m_data == nullptr;
    }

    char* object::buffer()
    {
        return m_buffer;
    }

    object::data* object::data_ptr()
    {
        return m_data;
    }

    object::data const* object::data_ptr() const
    {
        return m_data;
    }

    object::object(object::data* derived_data)
        : m_data(derived_data)
    {
        if (static_cast<void*>(derived_data) != static_cast<void*>(m_buffer))
        {
            m_data = nullptr; // m_data can't refer outside m_buffer
            DATA_EXCEPTION_THROW(exception, "Data should be initialized inside buffer of owner object.");
        }
    }

    object::object(std::nullptr_t)
        : m_data(nullptr)
    {
    }

#define DATA_OBJECT_DECLARE_CONSTRUCTOR(value_type, value_type_name) \
    object::object(value_type value) \
        : m_data(new(m_buffer) object::scalar_data<value_type>(value)) \
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

    template <>
    bool object::as() const
    {
        return m_data ? m_data->as_boolean() : false;
    }

    template <>
    int8_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 8-bit signed integer.");
        int64_t value = m_data->as_signed_integer();
        if (value & 0xFFFFFFFFFFFFFF00LL)
            DATA_EXCEPTION_THROW(exception, "Object value is out of range of 8-bit signed integer.");
        return static_cast<int8_t>(value);
    }

    template <>
    int16_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 16-bit signed integer.");
        int64_t value = m_data->as_signed_integer();
        if (value & 0xFFFFFFFFFFFF0000LL)
            DATA_EXCEPTION_THROW(exception, "Object value is out of range of 16-bit signed integer.");
        return static_cast<int16_t>(value);
    }

    template <>
    int32_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 32-bit signed integer.");
        int64_t value = m_data->as_signed_integer();
        if (value & 0xFFFFFFFF00000000LL)
            DATA_EXCEPTION_THROW(exception, "Object value is out of range of 32-bit signed integer.");
        return static_cast<int32_t>(value);
    }

    template <>
    int64_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 64-bit signed integer.");
        return m_data->as_signed_integer();
    }

    template <>
    uint8_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 8-bit unsigned integer.");
        uint64_t value = m_data->as_unsigned_integer();
        if (value & 0xFFFFFFFFFFFFFF00uLL)
            DATA_EXCEPTION_THROW(exception, "Object value is out of range of 8-bit unsigned integer.");
        return static_cast<uint8_t>(value);
    }

    template <>
    uint16_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 16-bit unsigned integer.");
        uint64_t value = m_data->as_signed_integer();
        if (value & 0xFFFFFFFFFFFF0000uLL)
            DATA_EXCEPTION_THROW(exception, "Object value is out of range of 16-bit unsigned integer.");
        return static_cast<uint16_t>(value);
    }

    template <>
    uint32_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 32-bit unsigned integer.");
        uint64_t value = m_data->as_signed_integer();
        if (value & 0xFFFFFFFF00000000uLL)
            DATA_EXCEPTION_THROW(exception, "Object value is out of range of 32-bit unsigned integer.");
        return static_cast<uint16_t>(value);
    }

    template <>
    uint64_t object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as 64-bit unsigned integer.");
        return m_data->as_signed_integer();
    }

    template <>
    float object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as single-precision floating-point value.");
        return m_data->as_single_precision();
    }

    template <>
    double object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as double-precision floating-point value.");
        return m_data->as_double_precision();
    }

    template <>
    decimal object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as decimal fixed-point value.");
        return m_data->as_decimal();
    }

    template <>
    text object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as text.");
        return m_data->as_decimal();
    }

    template <>
    char const* object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as byte-character string pointer.");
        return m_data->as_text().byte_char();
    }

    template <>
    wchar_t const* object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as wide-character string pointer.");
        return m_data->as_text().wide_char();
    }

    template <>
    std::string object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as byte-character string container.");
        return m_data->as_text().byte_string();
    }

    template <> DATA_API std::wstring object::as() const
    {
        if (!m_data)
            DATA_EXCEPTION_THROW(exception, "Object is null and can not be represented as byte-character string container.");
        return m_data->as_text().wide_string();
    }
    
}

// sine qua non
