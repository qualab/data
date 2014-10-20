/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <exception>

namespace data
{
    /// Base class for exception throwns from data namespace
    class DATA_API exception : public object, public std::exception
    {
    public:
        /// Create exception object
        exception();

        /// Create exception with message
        explicit exception(text message);

        /// Create exception with message and origin
        exception(text message, text file, int line, text function);
        
        /// Get exception associated message
        virtual text get_message() const;

        /// Get exception trace back to origin
        virtual trace get_trace() const;

        /// Override of std::exception::what
        virtual char const* what() const override;

    protected:
        /// Data of exception object
        class data;

    private:
        /// Stored pointer to exception::data
        data* m_data;
    };
}

// sine qua non
