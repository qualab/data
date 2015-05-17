/// @author Владимир Керимов

#pragma once

#include <data/memory>
#include <object/object_holder.hpp>
#include <string>

namespace data
{
    class memory::holder : public object::holder
    {
    public:
        holder();

        byte  operator [] (int index) const;
        byte& operator [] (int index);

        virtual object::holder* copy_to(void* address) const override;
        virtual object::holder* move_to(void* address) const override;

    private:
        std::string m_block;
    };
}

// sine qua non
