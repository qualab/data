/// @author Владимир Керимов

#include "text_data.hpp"

namespace data
{
    // Creation of null-object
    text::text()
    {
    }

    // Base virtual destructor
    object text::clone() const
    {
        return object(m_data.clone());
    }

    bool text::is_null() const
    {
        return m_data->is_null();
    }

    text::text(lazy<text::data> const& data)
        : m_data(data)
    {
    }
}

// sine qua non
