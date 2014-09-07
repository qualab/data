/// @author Владимир Керимов

#pragma once

#include <data/stdfwd>

namespace data
{
    template <typename value_type>
    class optional
    {
    public:
        optional();
        optional(std::nullptr_t);
        optional(value_type&& value);
        optional(optional const& another);
        optional(optional&& another);

        optional& operator = (std::nullptr_t);
        optional& operator = (value_type&& value);
        optional& operator = (optional const& another);
        optional& operator = (optional&& another);

        bool is_null() const;

        value_type get_value() const;
        value_type& get_reference();
        value_type const& get_const_reference() const;

        void clear();
        void reset(value_type&& value);
        void copy(optional const& another);
        void take(optional&& another);
        void swap(optional& another);

    private:
        value_type* m_value;
        char m_buffer[sizeof(value_type)];
        std::mutex m_clear;
        std::mutex m_reset;
    };
}

//  -- implementation of the template class methods --

template <typename value_type>
optional<value_type>::optional()
    : m_value(nullptr)
{
}

template <typename value_type>
optional<value_type>::optional(std::nullptr_t)
    : m_value(nullptr)
{
}

template <typename value_type>
optional<value_type>::optional(value_type&& value)
    : m_value(new(m_buffer) value_type(std::forward(value)))
{
}

template <typename value_type>
optional<value_type>::optional(optional<value_type> const& another)
    : m_value(another.m_value ? (new(m_buffer) value_type(*another.m_value)) : nullptr)
{
}

template <typename value_type>
optional<value_type>::optional(optional<value_type>&& another)
    : m_value(another.m_value ? (new(m_buffer) value_type(std::move(*another.m_value))) : nullptr)
{
    another.clear();
}

template <typename value_type>
optional<value_type>& optional<value_type>::operator = (std::nullptr_t)
{
    clear();
    return *this;
}

template <typename value_type>
optional<value_type>& optional<value_type>::operator = (value_type&& value)
{
    reset(std::forward(value));
    return *this;
}

template <typename value_type>
optional<value_type>& optional<value_type>::operator = (optional<value_type> const& another)
{
    copy(another);
    return *this;
}

template <typename value_type>
optional<value_type>& optional<value_type>::operator = (optional<value_type>&& another)
{
    take(another);
    return *this;
}

template <typename value_type>
void optional<value_type>::clear()
{
    if (m_value)
    {
        std::unique_lock lock(m_clear);
        if (m_value)
        {
            m_value.~value_type();
            m_value = nullptr;
        }
    }
}

template <typename value_type>
void optional<value_type>::reset(value_type&& value)
{
    std::unique_lock lock(m_reset);
    clear();
    m_value = new(m_buffer) value_type(std::forward(value));
}

template <typename value_type>
void optional<value_type>::copy(optional<value_type> const& another)
{
    std::unique_lock lock(another.m_clear);
    another.m_value ? reset(*another.m_value) : clear();
}

template <typename value_type>
void optional<value_type>::take(optional<value_type>&& another)
{
    {
        std::unique_lock lock(another.m_clear);
        another.m_value ? reset(std::move(*another.m_value)) : clear();
    }
    another.clear();
}

template <typename value_type>
void optional<value_type>::swap(optional<value_type>& another)
{
    optional<value_type> temporary(std::move(*this));
    {
        std::unique_lock lock(another.m_clear);
        another.m_value ? reset(*another.m_value) : clear();
    }
    another.take(temporary);
}

// sine qua non
