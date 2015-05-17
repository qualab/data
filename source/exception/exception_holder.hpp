/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <object/object_holder.hpp>
#include <tools/copy_on_write.hpp>

namespace data
{
    class exception::holder : public object::holder
    {
    public:
        holder();
        holder(text const& message);
        holder(text const& message, char const* file, int line, char const* function);

        text get_message() const;
        stacktrace get_stacktrace() const;

        virtual object::holder* copy_to(void* address) const override;
        virtual object::holder* move_to(void* address) const override;

    private:
        copy_on_write<instance> m_instance;
    };
}

// sine qua non
