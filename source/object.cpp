/// @author Владимир Керимов

#include <data/object>
#include <cstdint>

namespace data
{
    class object::data
    {
    public:
        data();
        virtual ~data();
        virtual bool is_null() const;
    };

//  object -----------------------------------------------------------------------

    // Creation of null-object
    object::object()
    {
    }

    // Base virtual destructor
    object::~object()
    {
    }

    object::object(object const& another)
        : m_data(another.m_data)
    {
    }

    object object::clone() const
    {
        return object(m_data.clone());
    }

    bool object::is_null() const
    {
        return true;
    }

    object::object(lazy<object::data> const& data)
        : m_data(data)
    {
    }

//  object::data -----------------------------------------------------------------

    object::data::data()
    {
    }

    object::data::~data()
    {
    }

    bool object::data::is_null() const
    {
        return true;
    }
}

// sine qua non