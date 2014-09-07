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
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(int32_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(int16_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(int8_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(uint64_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(uint32_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(uint16_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }

    template<>
    void object::set_as(uint8_t value)
    {
        m_data = std::make_shared<integer::data>(value);
    }
}

// sine qua non
