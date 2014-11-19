/// @author Владимир Керимов

#include <data_head/scalar_data.hpp>
#include <data/exception>
#include <data/decimal>
#include <data/text>
#include <data/stacktrace>
#include <string>

namespace data
{
    const object null;

    object::object()
        : m_data(nullptr)
    {
        DATA_CALL_INFO("Create null object by default constructor of data::object class.");
    }

    object::~object()
    {
        DATA_CALL_INFO("Destroy data::object and its data contained.");
        destruct();
    }

    void object::destruct()
    {
        DATA_CALL_INFO("Destruction of data::object data if object is not null.");
        if (m_data)
            m_data->~data();
    }

    object::object(object const& another)
        : m_data(another.m_data->copy_to(m_buffer))
    {
        DATA_CALL_INFO("Create object by copy from another data::object instance.");
    }

    object& object::operator = (object const& another)
    {
        DATA_CALL_INFO("Copy object from another data::object instance using assignment.");
        destruct();
        m_data = another.m_data->copy_to(m_buffer);
        return *this;
    }

    object::object(object&& temporary)
        : m_data(temporary.m_data->move_to(m_buffer))
    {
        DATA_CALL_INFO("Create object with moving object data from temporary data::object instance.");
    }

    object& object::operator = (object&& temporary)
    {
        DATA_CALL_INFO("Move object data from temporary data::object instance using assignment.");
        destruct();
        m_data = temporary.m_data->move_to(m_buffer);
        return *this;
    }

    object object::clone() const
    {
        DATA_CALL_INFO("Clone data::object and create new copy data contained in the new data::object instance.");
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
        DATA_CALL_INFO("Check is data::object contains null.");
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
        DATA_CALL_INFO("Create data::object with null value.");
    }

#define DATA_OBJECT_DECLARE_CONSTRUCTOR(value_type, value_type_name) \
    object::object(value_type value) \
        : m_data(new(m_buffer) object::scalar_data<value_type>(value)) \
    { \
        DATA_CALL_INFO("Create data::object by scalar value."); \
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
        DATA_CALL_INFO("Create data::object by byte-character C-string pointer.");
        *this = text(value);
    }

    object::object(wchar_t const* value)
        : m_data(nullptr)
    {
        DATA_CALL_INFO("Create data::object by wide-character C-string pointer.");
        *this = text(value);
    }

    object::object(std::string const& value)
        : m_data(nullptr)
    {
        DATA_CALL_INFO("Create data::object by standard byte-character string container.");
        *this = text(value);
    }

    object::object(std::wstring const& value)
        : m_data(nullptr)
    {
        DATA_CALL_INFO("Create data::object by standard wide-character string container.");
        *this = text(value);
    }

    template <>
    bool object::as() const
    {
        DATA_CALL_INFO("Get data::object value as boolean.");
        return m_data ? m_data->as_bool() : false;
    }

#define DATA_OBJECT_CHECK_NOT_NULL(type_name) \
    DATA_CALL_INFO("Get data::object value as " ## type_name); \
    if (!m_data) \
        DATA_EXCEPTION_THROW(null_representation_error, "Object is null and can not be represented as " ## type_name)

    template <>
    int8_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("8-bit signed integer");
        return m_data->as_int8();
    }

    template <>
    int16_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("16-bit signed integer");
        return m_data->as_int16();
    }

    template <>
    int32_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("32-bit signed integer");
        return m_data->as_int32();
    }

    template <>
    int64_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("64-bit signed integer");
        return m_data->as_int64();
    }

    template <>
    uint8_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("8-bit unsigned integer");
        return m_data->as_uint8();
    }

    template <>
    uint16_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("16-bit unsigned integer");
        return m_data->as_uint16();
    }

    template <>
    uint32_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("32-bit unsigned integer");
        return m_data->as_uint32();
    }

    template <>
    uint64_t object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("64-bit unsigned integer");
        return m_data->as_uint64();
    }

    template <>
    float object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("single-precision floating-point");
        return m_data->as_float();
    }

    template <>
    double object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("double-precision floating-point");
        return m_data->as_double();
    }

    template <>
    decimal object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("decimal fixed-point");
        return m_data->as_decimal();
    }

    template <>
    text object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("text");
        return m_data->as_text();
    }

    template <>
    char const* object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("byte-character C-string pointer");
        return m_data->as_text().byte_char();
    }

    template <>
    wchar_t const* object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("wide-character C-string pointer");
        return m_data->as_text().wide_char();
    }

    template <>
    std::string object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("byte-character standard string container");
        return m_data->as_text().byte_string();
    }

    template <> DATA_API std::wstring object::as() const
    {
        DATA_OBJECT_CHECK_NOT_NULL("wide-character standard string container");
        return m_data->as_text().wide_string();
    }    
}

// sine qua non
