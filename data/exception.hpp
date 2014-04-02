/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <exception>

namespace data
{
    class DATA_API exception : public object, public std::exception
    {
    public:
        exception();
        
        virtual char const* what() const override;

    protected:
        class data;
    };
}

// sine qua non
