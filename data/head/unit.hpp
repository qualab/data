/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for data query unit
    class DATA_API unit : public object
    {
    public:
        unit();

    protected:
        class data;
    };
}

// sine qua non
