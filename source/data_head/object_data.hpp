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

        // 
        virtual object get_element_copy() const;

        virtual object& get_element_reference();

        virtual object call_as_functor(object const another) const;

        virtual object binary_plus(object const& another) const;

        virtual object binary_minus(object const& another) const;

        virtual object binary_multiplication(object const& another) const;

        virtual object binary_division(object const& another) const;

        virtual object unary_plus() const;

        virtual object unary_minus() const;

        virtual int64_t  as_signed_integer() const;

        virtual uint64_t as_unsigned_integer() const;

        virtual double as_double_precision() const;

        virtual float as_single_precision() const;

        virtual decimal as_decimal() const;

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
