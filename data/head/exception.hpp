/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <exception>

#define DATA_EXCEPTION_THROW(exception_type, message) throw exception_type((message), (__FILE__), (__LINE__), (__FUNCTION__))

#ifdef _MSC_VER
#define noexcept throw()
#endif

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
        exception(text const& message, char const* file, int line, char const* function);

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

    template <class tag_type, class base_exception = exception>
    class exception_class : public base_exception
    {
    public:
        typedef base_exception base;
        typedef exception_class type;

        exception_class()
        {
        }

        exception_class(text const& message)
            : base(message)
        {
        }

        exception_class(text const& message, char const* file, int line, char const* function)
            : base(message, file, line, function)
        {
        }
    };

    /// "Operation is not supported" exception
    typedef exception_class<class operation_no_supported_tag> operation_not_supported;

    /// "Nonexistent type cast between the types specified" exception
    typedef exception_class<class nonexistent_type_cast_tag> nonexistent_type_cast;
}

// sine qua non
