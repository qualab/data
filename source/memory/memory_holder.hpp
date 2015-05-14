/// @author Владимир Керимов

#pragma once

#include <data/memory>
#include <object/object_holder.hpp>
#include <string>

namespace data
{
    class byte_array::holder : public object::holder
    {
    public:
        data();

        data(void* start, int length);
        data(void* start, void* end);

        byte  operator [] (int index) const;
        byte& operator [] (int index);

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        std::string m_block;
    };
}

// sine qua non
