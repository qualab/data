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

    bool object::data::as_boolean() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as boolean.");
    }   

    int64_t  object::data::as_signed_integer() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as signed integer.");
    }

    uint64_t object::data::as_unsigned_integer() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as unsigned integer.");
    }

    double object::data::as_double_precision() const
    {
        DATA_EXCEPTION_THROW(exception, "Object is not supporting retrievement as double-precision floating-point value.");
    }

    float object::data::as_single_precision() const
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
