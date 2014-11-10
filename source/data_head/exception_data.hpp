/// @author Владимир Керимов

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
        data(text const& message, trace const& traceback);

        text get_message() const;
        trace get_trace() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    protected:
        class body;

    private:
        lazy_data<body> m_body;
    };
}

// sine qua non
