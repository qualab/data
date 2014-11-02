/// @author Владимир Керимов

#include <data_head/object_data.hpp>
#include <data/exception>
#include <data/decimal>

namespace data
{
    object::data::data()
    {
    }

    object::data::~data()
    {
    }

    object object::data::get_element_copy() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement of the element of sequence.");
    }

    object& object::data::get_element_reference()
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement of reference to the element of sequence.");
    }

    object object::data::call_as_functor(object const another) const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not a functor and not support interface of calling.");
    }

    object object::data::binary_plus(object const& another) const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting interface of binary addition.");
    }

    object object::data::binary_minus(object const& another) const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting interface of binary negation.");
    }

    object object::data::binary_multiplication(object const& another) const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting interface of multiplacation.");
    }

    object object::data::binary_division(object const& another) const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting interface of division.");
    }

    object object::data::unary_plus() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting interface of unary plus.");
    }

    object object::data::unary_minus() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting interface of unary minus.");
    }

    bool object::data::as_bool() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as boolean.");
    }   

    int64_t object::data::as_int64() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 64-bit signed integer.");
    }

    int32_t object::data::as_int32() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 32-bit signed integer.");
    }

    int16_t object::data::as_int16() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 16-bit signed integer.");
    }

    int8_t object::data::as_int8() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 8-bit signed integer.");
    }

    uint64_t object::data::as_uint64() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 64-bit unsigned integer.");
    }

    uint32_t object::data::as_uint32() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 32-bit unsigned integer.");
    }

    uint16_t object::data::as_uint16() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 16-bit unsigned integer.");
    }

    uint8_t object::data::as_uint8() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as 8-bit unsigned integer.");
    }

    double object::data::as_double() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as double-precision floating-point value.");
    }

    float object::data::as_float() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as single-precision floating-point value.");
    }

    decimal object::data::as_decimal() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as decimal fixed-point value.");
    }

    text object::data::as_text() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as text.");
    }
}

// sine qua non
