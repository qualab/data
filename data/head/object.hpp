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

        /// Create object of logical value
        explicit object(bool value);

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

        /// Create object of 16-bit unsigned integer 
        explicit object(uint16_t value);

        /// Create object of 32-bit unsigned integer 
        explicit object(uint32_t value);

        /// Create object of 64-bit unsigned integer 
        explicit object(uint64_t value);

        /// Create object of single precision floating point value
        explicit object(float value);

        /// Create object of double precision floating point value
        explicit object(double value);

        /// Create object of ANSI string
        explicit object(char const* value);

        /// Create object of wide character string
        explicit object(wchar_t const* value);

        /// Create object of standard container of ANSI string
        explicit object(std::string const& value);

        /// Create object of standard container of wide character string
        explicit object(std::wstring const& value);

        /// Indexing by constant object
        object operator [] (object const& id) const;

        /// Indexing by non-constant object
        object& operator [] (object const& index);

        /// Call functor as constant object with constant arguments
        object operator () (object const& arguments) const;

        /// Add another object to this
        object operator + (object const& another) const;

        /// Subtract another object from this
        object operator - (object const& another) const;

        /// Multiply this object to another
        object operator * (object const& another) const;

        /// Divide this object to another
        object operator / (object const& another) const;

        /// Unary plus
        object operator + () const;

        /// Unary minus
        object operator - () const;

    protected:
        /// Base object data class
        class data;

        /// Constant of max available size for data
        static const size_t data_max_size = DATA_MAX_SIZE;

        /// Address of buffer
        char* buffer();

        /// Create object by derived data
        object(data* derived_data);

        /// Create object by prepared_data
        object(data&& prepared_data);

        /// Scalar data storage
        template <typename value_type>
        class scalar_data;

    public:
        /// Pointer to the data
        data* data_ptr();

        /// Constant pointer to the data
        data const* data_ptr() const;

    private:
        /// Reference to the base object::data
        data* m_data;

        /// Data buffer must be greater size than any possible data
        char m_buffer[data_max_size];

        /// Destruct data
        void destruct();
    };

// --- additional declarations part --- //

    /// Write object into the byte stream
    DATA_API std::ostream& operator << (std::ostream& output, object const& value);

    /// Read object from the byte stream
    DATA_API std::istream& operator >> (std::istream& input, object& value);

    /// Representation of null constant
    DATA_API extern const object null;

//  data::object

    template <typename value_type>
    value_type object::as() const
    {
       static_assert(false, "Not supported type to get object as the type specified.");
    }

    /// Get object as value of boolean type
    template <> DATA_API bool object::as() const;

    /// Get object as 8-bit signed integer value
    template <> DATA_API int8_t object::as() const;

    /// Get object as 16-bit signed integer value
    template <> DATA_API int16_t object::as() const;

    /// Get object as 32-bit signed integer value
    template <> DATA_API int32_t object::as() const;

    /// Get object as 64-bit signed integer value
    template <> DATA_API int64_t object::as() const;

    /// Get object as 8-bit unsigned integer value
    template <> DATA_API uint8_t object::as() const;

    /// Get object as 16-bit unsigned integer value
    template <> DATA_API uint16_t object::as() const;

    /// Get object as 32-bit unsigned integer value
    template <> DATA_API uint32_t object::as() const;

    /// Get object as 64-bit unsigned integer value
    template <> DATA_API uint64_t object::as() const;

    /// Get object as single-precision floating-point value
    template <> DATA_API float object::as() const;

    /// Get object as double-precision floating-point value
    template <> DATA_API double object::as() const;

    /// Get object as decimal fixed-point value
    template <> DATA_API decimal object::as() const;

    /// Get object as text
    template <> DATA_API text object::as() const;

    /// Get object as pointer to byte character string
    template <> DATA_API char const* object::as() const;

    /// Get object as pointer to wide character string
    template <> DATA_API wchar_t const* object::as() const;

    /// Get object as standard byte character string
    template <> DATA_API std::string object::as() const;

    /// Get object as stardard wide character string
    template <> DATA_API std::wstring object::as() const;
}

// sine qua non
