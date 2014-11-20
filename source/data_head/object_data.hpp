/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <memory>

#define DATA_OBJECT_CREATE(data_type, arguments) \
    : object(new(buffer()) data_type arguments)

namespace data
{
    // base class for data of object
    class object::data
    {
    public:
        // create null object
        data();

        // destruct data
        virtual ~data();

        // copy data of object into the buffer specified
        virtual data* copy_to(void* address) const = 0;

        // move data of object into the buffer specified
        virtual data* move_to(void* address) const = 0;

        // return the value of element of collection represented by object
        virtual object get_element_copy() const;

        // access by reference to the element of collection represented by object
        virtual object& get_element_reference();

        // call functor object
        virtual object call_as_functor(object const another) const;

        // binary plus operation
        virtual object binary_plus(object const& another) const;

        // binary minus operation
        virtual object binary_minus(object const& another) const;

        // operation of multiplication
        virtual object binary_multiplication(object const& another) const;

        // operation of division
        virtual object binary_division(object const& another) const;

        // unary plus operation
        virtual object unary_plus() const;

        // unary minus operation
        virtual object unary_minus() const;

        // get object as 64-bit signed integer value
        virtual bool as_bool() const;

        // get object as 64-bit signed integer value
        virtual int64_t as_int64() const;

        // get object as 32-bit signed integer value
        virtual int32_t as_int32() const;

        // get object as 16-bit signed integer value
        virtual int16_t as_int16() const;

        // get object as 8-bit signed integer value
        virtual int8_t as_int8() const;

        // get object as 64-bit unsigned integer value
        virtual uint64_t as_uint64() const;

        // get object as 32-bit unsigned integer value
        virtual uint32_t as_uint32() const;

        // get object as 16-bit unsigned integer value
        virtual uint16_t as_uint16() const;

        // get object as 8-bit unsigned integer value
        virtual uint8_t as_uint8() const;

        // get object as double-precision floating-point value
        virtual double as_double() const;

        // get object as single-precision floating-point value
        virtual float as_float() const;

        // get object as decimal fixed-point value
        virtual decimal as_decimal() const;

        // get object as text
        virtual text as_text() const;
    };
}

// sine qua non
