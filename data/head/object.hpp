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

        /// Implicit cast to boolean
        operator bool() const;

        /// Implicit cast to 64-bit signed integer
        operator int64_t() const;

        /// Implicit cast to 32-bit signed integer
        operator int32_t() const;

        /// Implicit cast to 16-bit signed integer
        operator int16_t() const;

        /// Implicit cast to 8-bit signed integer
        operator int8_t() const;

        /// Implicit cast to 64-bit unsigned integer
        operator uint64_t() const;

        /// Implicit cast to 32-bit unsigned integer
        operator uint32_t() const;

        /// Implicit cast to 16-bit unsigned integer
        operator uint16_t() const;

        /// Implicit cast to 8-bit unsigned integer
        operator uint8_t() const;

        /// Implicit cast to single-precision floating-point value
        operator float() const;

        /// Implicit cast to double-precision floating-point value
        operator double() const;

        /// Implicit cast to fixed-point decimal value
        operator decimal() const;

        /// Implicit cast to text
        operator text() const;

        /// Implicit cast to byte-character null-terminated string pointer
        operator char const*() const;

        /// Implicit cast to wide-character null-terminated string pointer
        operator wchar_t const*() const;

        /// Implicit cast to byte-character standard string container
        operator std::string() const;

        /// Implicit cast to wide-character standard string container
        operator std::wstring() const;

        /// Clone data into new object
        object clone() const;

        /// Check is object null
        bool is_null() const;

        /// Create object of null value
        object(std::nullptr_t);

        /// Create object of logical value
        object(bool value);

        /// Create object of 8-bit signed integer
        object(int8_t value);

        /// Create object of 16-bit signed integer
        object(int16_t value);

        /// Create object of 32-bit signed integer
        object(int32_t value);

        /// Create object of 64-bit signed integer
        object(int64_t value);

        /// Create object of 8-bit unsigned integer
        object(uint8_t value);

        /// Create object of 16-bit unsigned integer
        object(uint16_t value);

        /// Create object of 32-bit unsigned integer
        object(uint32_t value);

        /// Create object of 64-bit unsigned integer
        object(uint64_t value);

        /// Create object of single precision floating point value
        object(float value);

        /// Create object of double precision floating point value
        object(double value);

        /// Create object of ANSI string
        object(char const* value);

        /// Create object of wide character string
        object(wchar_t const* value);

        /// Create object of standard container of ANSI string
        object(std::string const& value);

        /// Create object of standard container of wide character string
        object(std::wstring const& value);

        /// Create object of function
        object(std::function<object(object const& arguments)> const value);

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

        /// Size of object presented collection
        size_t size() const;

        /// Iterator of the beginning of collection presented by object
        iterator begin();

        /// Iterator of the beginning of collection presented by object
        iterator end();

        /// Constant iterator of the beginning of collection presented by object
        const_iterator begin() const;

        /// Constant iterator of the beginning of collection presented by object
        const_iterator end() const;

        /// Constant iterator of the beginning of collection presented by object
        const_iterator cbegin() const;

        /// Constant iterator of the beginning of collection presented by object
        const_iterator cend() const;

        /// Find element of collection by key and return iterator to it
        iterator find(object const& key);

        /// Find element of collection by key and return constant iterator to it
        const_iterator find(object const& key) const;

        /// Find element of collection by predicate and return iterator to it
        iterator find(std::function<void(object& elem)> const& predicate);

        /// Find element of collection by predicate and return constant iterator to it
        const_iterator find(std::function<void(object const& elem)> const& predicate) const;

        /// Apply unary operation to each element in collection and store the results
        object unary_operation(std::function<object(object& elem)> const& operation);

        /// Apply unary operation to each element in collection and store the results
        object unary_operation(std::function<object(object const& elem)> const& operation) const;

        /// Apply unary operation to each element in collection and store the results
        object binary_operation(object& another, std::function<object(object& mine, object& their)> const& operation);

        /// Apply unary operation to each element in collection and store the results
        object binary_operation(object const& another, std::function<object(object const& mine, object const& their)> const& operation) const;

        /// Execute the function represented by object
        object operator()(object const& arguments) const;

        /// Apply unary operation to each element in collection and store the results
        object binary_operation(object const& another, std::function<object(object const& mine, object const& their)> const& operation) const;

    protected:
        /// Base object data class
        class data;

        /// Constant of max available size for data
        static const int data_max_size = DATA_MAX_SIZE;

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
