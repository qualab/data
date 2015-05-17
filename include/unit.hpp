/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/nullable>

namespace data
{
    /// Type for data query unit
    class DATA_API unit : public object
    {
    public:
        unit();

    protected:
        class holder;
        class instance;

    private:
        nullable<holder> m_holder;
    };
}

// sine qua non
