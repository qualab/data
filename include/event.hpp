/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/nullable>
#include <exception>

namespace data
{
    /// Base class for other events
    class DATA_API event : public object
    {
    public:
        /// Create exception object
        event();

    protected:
        /// Data of exception object
        class holder;
        class instance;

    private:
        /// Stored pointer to exception::data
        nullable<holder> m_holder;
    };
}

// sine qua non
