/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <exception>

namespace data
{
    class text;
    class trace;

    class DATA_API exception : public object, public std::exception
    {
    public:
        exception();

        exception(text message);
        exception(text message, text file, int line, text function);
        
        virtual text get_message() const;
        virtual trace get_trace() const;

        virtual char const* what() const override;

    protected:
        class data;

        exception(std::shared_ptr<data>&& prepared_data);

        friend class object;

    private:
        data* m_data;
    };
}

// sine qua non
