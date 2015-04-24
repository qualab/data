/// @author Владимир Керимов

#pragma once

#include <data_head/object_data.hpp>
#include <data/exception>
#include <data/decimal>
#include <data/text>
#include <data/cast>

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

        virtual bool as_bool() const override;

        virtual int64_t as_int64() const override;

        virtual int32_t as_int32() const override;

        virtual int16_t as_int16() const override;

        virtual int8_t as_int8() const override;

        virtual uint64_t as_uint64() const override;

        virtual uint32_t as_uint32() const override;

        virtual uint16_t as_uint16() const override;

        virtual uint8_t as_uint8() const override;

        virtual double as_double() const override;

        virtual float as_float() const override;

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

    template <typename value_type>
    bool object::scalar_data<value_type>::as_bool() const
    {
        return cast<bool>(m_value);
    }

    template <typename value_type>
    int64_t object::scalar_data<value_type>::as_int64() const
    {
        return cast<int64_t>(m_value);
    }

    template <typename value_type>
    int32_t object::scalar_data<value_type>::as_int32() const
    {
        return cast<int32_t>(m_value);
    }

    template <typename value_type>
    int16_t object::scalar_data<value_type>::as_int16() const
    {
        return cast<int16_t>(m_value);
    }

    template <typename value_type>
    int8_t object::scalar_data<value_type>::as_int8() const
    {
        return cast<int8_t>(m_value);
    }

    template <typename value_type>
    uint64_t object::scalar_data<value_type>::as_uint64() const
    {
        return cast<uint64_t>(m_value);
    }

    template <typename value_type>
    uint32_t object::scalar_data<value_type>::as_uint32() const
    {
        return cast<uint32_t>(m_value);
    }

    template <typename value_type>
    uint16_t object::scalar_data<value_type>::as_uint16() const
    {
        return cast<uint16_t>(m_value);
    }

    template <typename value_type>
    uint8_t object::scalar_data<value_type>::as_uint8() const
    {
        return cast<uint8_t>(m_value);
    }

    template <typename value_type>
    double object::scalar_data<value_type>::as_double() const
    {
        return cast<double>(m_value);
    }

    template <typename value_type>
    float object::scalar_data<value_type>::as_float() const
    {
        return cast<float>(m_value);
    }

    template <typename value_type>
    decimal object::scalar_data<value_type>::as_decimal() const
    {
        return cast<decimal>(m_value);
    }

    template <typename value_type>
    text object::scalar_data<value_type>::as_text() const
    {
        return cast<text>(m_value);
    }
}

// sine qua non
