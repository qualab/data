/// @author Владимир Керимов

#include <data_head/boolean_data.hpp>

namespace data
{
    boolean::boolean()
    {
    }

    boolean::boolean(bool value)
        : m_data(new boolean::data(value)), object(m_data)
    {
    }

    boolean::boolean(std::nullptr_t)
    {
    }

    template<>
    void object::set_as(bool value)
    {
        m_data = std::make_shared<boolean::data>(value);
    }
}

// sine qua non
