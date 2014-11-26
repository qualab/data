/// @author Владимир Керимов

#pragma once

#include <data/bytes>
#include <data_head/object_data.hpp>

namespace data
{
    class bytes::data : public object::data
    {
    public:
        data();

    private:
        std::string m_array;
    };
}

// sine qua non
