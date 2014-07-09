/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for data query construct, request and read response
    class DATA_API query : public object
    {
    public:
        query();

    protected:
        class data;
    };
}

// sine qua non
