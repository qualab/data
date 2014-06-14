/// @author Владимир Керимов

#include <data_head/integer_data.hpp>

namespace data
{
    integer::integer()
    {
    }

    template<>
    void object::set_as(int64_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(value)));
    }

    template<>
    void object::set_as(int32_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(value)));
    }

    template<>
    void object::set_as(int16_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(value)));
    }

    template<>
    void object::set_as(int8_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(value)));
    }

    template<>
    void object::set_as(uint64_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(static_cast<int64_t>(value))));
    }

    template<>
    void object::set_as(uint32_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(static_cast<int32_t>(value))));
    }

    template<>
    void object::set_as(uint16_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(static_cast<int16_t>(value))));
    }

    template<>
    void object::set_as(uint8_t value)
    {
        m_data.reset(new lazy<object::data>(new integer::data(static_cast<int8_t>(value))));
    }
}

// sine qua non
