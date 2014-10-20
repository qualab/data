/// @author Владимир Керимов

#include <data_head/boolean_data.hpp>

namespace data
{
    boolean::data::data(bool value)
        : m_value(value)
    {
    }

    bool boolean::data::is_null() const
    {
        return false;
    }

    std::shared_ptr<object::data> boolean::data::clone() const
    {
        return std::make_shared<boolean::data>(*this);
    }

    bool boolean::data::get_value() const
    {
        return m_value;
    }

    void boolean::data::set_value(bool value)
    {
        m_value = value;
    }
}

// sine qua non
