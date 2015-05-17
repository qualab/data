/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <data/text>
#include <data/stacktrace>
#include <object/object_holder.hpp>
#include <tools/copy_on_write.hpp>

namespace data
{
    class exception::instance
    {
    public:
        instance();
        instance(text const& message);
        instance(text const& message, char const* file, int line, char const* function);

        text get_message() const;
        stacktrace get_stacktrace() const;

    private:
        text m_message;
        stacktrace m_stacktrace;
    };
}

// sine qua non
