/// @author Владимир Керимов

#include <data_head/boolean_data.hpp>
#include <data/exception>

namespace data
{
    boolean::boolean()
        : object(), m_data()
    {
    }

    boolean::boolean(bool value)
        : object(), m_data()
    {
        set_value(value);
    }

    boolean::boolean(std::nullptr_t)
        : object(), m_data()
    {
    }

    boolean::boolean(boolean const& another)
        : object(), m_data()
    {
        set_value(another.get_value());
    }

    boolean::boolean(object const& another)
        : object(), m_data()
    {
        *this = another;
    }

    boolean& boolean::operator = (boolean const& another)
    {
        set_value(another.get_value());
        return *this;
    }

    void boolean::set_value(bool value)
    {
        set_data(std::shared_ptr<object::data>((m_data = new boolean::data(value))));
    }

    bool boolean::get_value() const
    {
        return m_data->get_value();
    }

    template<>
    void object::set_as(bool value)
    {
        *this = boolean(value);
    }
}

// sine qua non
