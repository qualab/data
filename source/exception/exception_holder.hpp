﻿/// @author Владимир Керимов

#pragma once

#include <data/exception>
#include <data_head/object_data.hpp>
#include <data_head/lazy_data.hpp>

namespace data
{
    class exception::data : public object::data
    {
    public:
        data();
        data(text const& message);
        data(text const& message, char const* file, int line, char const* function);

        text get_message() const;
        stacktrace get_stacktrace() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    protected:
        class body;

    private:
        lazy_data<body> m_body;
    };
}

// sine qua non