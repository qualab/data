/// @author Владимир Керимов

#pragma once

#include <data/stacktrace>
#include <object/object_holder.hpp>
#include <tools/copy_on_write.hpp>

namespace data
{
    class stacktrace::holder : public object::holder
    {
    public:
        stacktrace();

    private:
        copy_on_write<instance> m_instance;
    };
}

// sine qua non
