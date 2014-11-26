/// @author Владимир Керимов

#pragma once

#include <data/bytes>
#include <data_head/object_data.hpp>
#include <string>

namespace data
{
    class bytes::data : public object::data
    {
    public:
        data();

        data(void* start, int length);
        data(void* start, void* end);

        byte  operator [] (int index) const;
        byte& operator [] (int index);

    private:
        std::string m_block;
    };
}

// sine qua non
