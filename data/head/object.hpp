/// @author Владимир Керимов

#pragma once

#include <data/api>
#include <data/stdfwd>
#include <cstdint>

namespace data
{
    /// Base type for any data type
    class DATA_API object
    {
    public:
        /// Create null-object
        object();

        /// Base scalar destructor
        ~object();

        /// Create with copy of data from another object
        object(object const& another);

        /// Copy data from another object
        object& operator = (object const& another);

        /// Create with data moved from r-value reference
        object(object&& temporary);

        /// Move data from r-value reference
        object& operator = (object&& temporary);

        /// Get object as value of specified type
        template <typename value_type>
        value_type as() const;

        /// Clone data into new object
        object clone() const;

        /// Check is object null
        bool is_null() const;

        /// Create object of null value
        explicit object(std::nullptr_t);

        /// Create object of 8-bit signed integer 
        explicit object(int8_t value);

        /// Create object of 16-bit signed integer 
        explicit object(int16_t value);

        /// Create object of 32-bit signed integer 
        explicit object(int32_t value);

        /// Create object of 64-bit signed integer 
        explicit object(int64_t value);

        /// Create object of 8-bit unsigned integer 
        explicit object(uint8_t value);

        /// Create object of 8-bit unsigned integer 
        explicit object(uint16_t value);

        /// Create object of 8-bit unsigned integer 
        explicit object(uint32_t value);

        /// Create object of 8-bit unsigned integer 
        explicit object(uint64_t value);

        /// Create object of single precision floating point value
        explicit object(float value);

        /// Create object of double precision floating point value
        explicit object(double value);

        /// Create object of ansi-char string
        explicit object(char const* value);

        /// Create object of wide-char string
        explicit object(wchar_t const* value);

    protected:
        /// Base object data class
        class data;

        /// Constant of max available size for data
        static const size_t data_max_size = DATA_MAX_SIZE;

        /// Address of buffer
        char* buffer();

        /// Create object by prepared data
        object(data&& prepared);

    private:
        /// Reference to the base object::data
        data* m_data;

        /// Data buffer must be greater size than any possible data
        char m_buffer[data_max_size];

        /// Destruct data
        void destruct();
    };

    /// Representation of null constant
    DATA_API extern const object null;

//  data::object

    // Getter-methods
    template<> DATA_API bool     object::as() const;
    template<> DATA_API int8_t   object::as() const;
    template<> DATA_API int16_t  object::as() const;
    template<> DATA_API int32_t  object::as() const;
    template<> DATA_API int64_t  object::as() const;
    template<> DATA_API uint8_t  object::as() const;
    template<> DATA_API uint16_t object::as() const;
    template<> DATA_API uint32_t object::as() const;
    template<> DATA_API uint64_t object::as() const;
    template<> DATA_API float    object::as() const;
    template<> DATA_API double   object::as() const;
    template<> DATA_API decimal  object::as() const;
    template<> DATA_API text     object::as() const;
    template<> DATA_API char    const* object::as() const;
    template<> DATA_API wchar_t const* object::as() const;
    template<> DATA_API std::string    object::as() const;
    template<> DATA_API std::wstring   object::as() const;
}

// sine qua non
