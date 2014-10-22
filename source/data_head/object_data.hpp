/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <memory>

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

        // clone data of object into the new object
        virtual object clone() const = 0;

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
        virtual int64_t as_signed_integer() const;

        // get object as 64-bit unsigned integer value
        virtual uint64_t as_unsigned_integer() const;

        // get object as double-precision floating-point value
        virtual double as_double_precision() const;

        // get object as single-precision floating-point value
        virtual float as_single_precision() const;

        // get object as decimal fixed-point value
        virtual decimal as_decimal() const;

        // get object as text
        virtual text as_text() const;
    };

    template <typename value_type>
    class scalar_data : public object::data
    {
    public:
        scalar_data(value_type value)
            : m_value(value) {
        }

        value_type value() const {
            return m_value;
        }

        virtual object clone() const override {
            return object(scalar_data(*this));
        }

        virtual data* copy_to(void* address) const override {
            return new(address) scalar_data(*this);
        }

        virtual data* move_to(void* address) const override {
            return new(address) scalar_data(std::move(*this));
        }

    private:
        value_type m_value;
    };
}

// sine qua non
