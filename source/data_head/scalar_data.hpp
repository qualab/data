/// @author Владимир Керимов

#pragma once

#include <data_head/object_data.hpp>
#include <data/exception>
#include <data/decimal>
#include <data/text>

namespace data
{
    template <typename value_type>
    class object::scalar_data : public object::data
    {
    public:
        scalar_data(value_type value);

        value_type value() const;

        virtual data* copy_to(void* address) const override;

        virtual data* move_to(void* address) const override;

        virtual object binary_plus(object const& another) const override;

        virtual object binary_minus(object const& another) const override;

        virtual object binary_multiplication(object const& another) const override;

        virtual object binary_division(object const& another) const override;

        virtual object unary_plus() const override;

        virtual object unary_minus() const override;

        virtual bool as_boolean() const override;

        virtual int64_t as_signed_integer() const override;

        virtual uint64_t as_unsigned_integer() const override;

        virtual double as_double_precision() const override;

        virtual float as_single_precision() const override;

        virtual decimal as_decimal() const override;

        virtual text as_text() const override;

     private:
        value_type m_value;
    };

    template <typename value_type>
    object::scalar_data<value_type>::scalar_data(value_type value)
        : m_value(value)
    {
    }

    template <typename value_type>
    value_type object::scalar_data<value_type>::value() const
    {
        return m_value;
    }

    template <typename value_type>
    object::data* object::scalar_data<value_type>::copy_to(void* address) const
    {
        return new(address) scalar_data(*this);
    }

    template <typename value_type>
    object::data* object::scalar_data<value_type>::move_to(void* address) const
    {
        return new(address) scalar_data(std::move(*this));
    }

    template <typename value_type>
    object object::scalar_data<value_type>::binary_plus(object const& another) const
    {
        return object::data::binary_plus(another);
    }

    template <typename value_type>
    object object::scalar_data<value_type>::binary_minus(object const& another) const
    {
        return object::data::binary_minus(another);
    }

    template <typename value_type>
    object object::scalar_data<value_type>::binary_multiplication(object const& another) const
    {
        return object::data::binary_multiplication(another);
    }

    template <typename value_type>
    object object::scalar_data<value_type>::binary_division(object const& another) const
    {
        return object::data::binary_division(another);
    }

    template <typename value_type>
    object object::scalar_data<value_type>::unary_plus() const
    {
        return object::data::unary_plus();
    }

    template <typename value_type>
    object object::scalar_data<value_type>::unary_minus() const
    {
        return object::data::unary_minus();
    }

    template <typename result_type, typename value_type>
    bool cast_to_boolean(value_type value);

    template <typename value_type>
    typename std::enable_if<std::is_integral<value_type>::value, bool>::type cast_to_boolean(value_type value)
    {
        return value != 0;
    }

    template <typename value_type>
    bool object::scalar_data<value_type>::as_boolean() const
    {
        return cast_to_boolean(m_value);
    }

    template <typename result_type, typename value_type>
    result_type cast_to_signed_integer(value_type value);

    template <>
    int64_t cast_to_signed_integer(bool value)
    {
        return value ? 1 : 0;
    }

    template <typename value_type>
    typename std::enable_if<std::is_floating_point<value_type>::value, int64_t>::type cast_to_signed_integer(value_type value)
    {
        if (value < static_cast<value_type>(std::numeric_limits<int64_t>::min()) ||
            value > static_cast<value_type>(std::numeric_limits<int64_t>::max()))
        {
            DATA_EXCEPTION_THROW(exception, "TODO: exception");
        }
        return static_cast<int64_t>(value);
    }

    template <typename value_type>
    typename std::enable_if<std::is_integral<value_type>::value, int64_t>::type cast_to_signed_integer(value_type value)
    {
        return static_cast<int64_t>(value);
    }

    template <typename value_type>
    typename std::enable_if<!std::is_integral<value_type>::value && !std::is_floating_point<value_type>::value, int64_t>::type cast_to_signed_integer(value_type value)
    {
        throw 1; // TODO: implement any cast to int64_t
    }

    template <typename value_type>
    int64_t object::scalar_data<value_type>::as_signed_integer() const
    {
        return cast_to_signed_integer(m_value);
    }

    template <typename value_type>
    uint64_t object::scalar_data<value_type>::as_unsigned_integer() const
    {
        return object::data::as_unsigned_integer();
    }

    template <typename result_type, typename value_type>
    result_type cast_to_double_precision();

    template <typename value_type>
    typename std::enable_if<std::is_floating_point<value_type>::value, double>::type cast_to_double_precision(value_type value)
    {
        return static_cast<double>(value);
    }

    template <typename value_type>
    typename std::enable_if<!std::is_floating_point<value_type>::value, double>::type cast_to_double_precision(value_type value)
    {
        throw 2; // TODO: implement any cast to double
    }

    template <typename value_type>
    double object::scalar_data<value_type>::as_double_precision() const
    {
        return cast_to_double_precision(m_value);
    }

    template <typename value_type>
    float object::scalar_data<value_type>::as_single_precision() const
    {
        return object::data::as_single_precision();
    }

    template <typename value_type>
    decimal object::scalar_data<value_type>::as_decimal() const
    {
        return object::data::as_decimal();
    }

    template <typename value_type>
    text object::scalar_data<value_type>::as_text() const
    {
        return object::data::as_text();
    }
}

// sine qua non
