/// @author Владимир Керимов

#pragma once

#include <data_head/object_data.hpp>

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
}

// sine qua non
