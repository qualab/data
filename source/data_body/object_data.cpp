/// @author Владимир Керимов

#include <data_head/object_data.hpp>
#include <data/exception>

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
        DATA_EXCEPTION_THROW(exception, "");
    }

    object& object::data::get_element_reference()
    {
    }

    object object::data::call_as_functor(object const another) const
    {
    }

    object object::data::binary_plus(object const& another) const
    {
    }

    object object::data::binary_minus(object const& another) const
    {
    }

    object object::data::binary_multiplication(object const& another) const
    {
    }

    object object::data::binary_division(object const& another) const
    {
    }

    object object::data::unary_plus() const
    {
    }

    object object::data::unary_minus() const
    {
    }

    int64_t  object::data::as_signed_integer() const
    {
    }

    uint64_t object::data::as_unsigned_integer() const
    {
    }

    double object::data::as_double_precision() const
    {
    }

    float object::data::as_single_precision() const
    {
    }

    decimal object::data::as_decimal() const
    {
    }

    text object::data::as_text() const
    {
    }
}

// sine qua non
