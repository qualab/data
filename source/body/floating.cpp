/// @author Владимир Керимов

#include <data_head/floating_data.hpp>

namespace data
{
    floating::floating()
    {
    }

    template<>
    void object::set_as(double value)
    {
        m_data = std::make_shared<floating::data>(value);
    }

    template<>
    void object::set_as(float value)
    {
        m_data = std::make_shared<floating::data>(value);
    }
}

// sine qua non
