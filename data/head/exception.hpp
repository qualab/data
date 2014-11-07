/// @author Владимир Керимов

#pragma once

#include <data/text>
#include <exception>

#define DATA_EXCEPTION_THROW(exception_type, message) throw exception_type(text(message), text(__FILE__), int(__LINE__), text(__FUNCTION__))

namespace data
{
    /// Base class for exception throwns from data namespace
    class DATA_API exception : public object, public std::exception
    {
    public:
        /// Create exception object
        exception();

        /// Create exception with message
        explicit exception(text const& message);

        /// Create exception with message and origin
        exception(text const& message, text const& file, int line, text const& function);
        
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

    /// "Operation is not supported" exception
    class DATA_API operation_not_supported : public exception
    {
    public:
        /// Create an "Operation is not supported" exception with this message by default
        operation_not_supported();

        /// Create an "Operation is not supported" exception with the message specified
        operation_not_supported(text const& message);

        /// Create an "Operation is not supported" exception with the message specified and source origin
        operation_not_supported(text const& message, text const& file, int line, text const& function);
    };

    /// "Nonexistent type cast between the types specified" exception
    class DATA_API nonexistent_type_cast : public exception
    {
    public:
        /// "Nonexistent type cast between the types specified" exception with this message by default
        nonexistent_type_cast();

        /// "Nonexistent type cast between the types specified" exception with the message specified
        nonexistent_type_cast(text const& message);

        /// "Nonexistent type cast between the types specified" exception with the message specified and source origin
        nonexistent_type_cast(text const& message, text const& file, int line, text const& function);
    };
}

// sine qua non
