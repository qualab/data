/// @author Владимир Керимов

#pragma once

#include <data/api>
#include <data/lazy>
#include <cstdint>
#include <cstddef>

namespace data
{
    /// Base type for any data type
    class DATA_API object
    {
    public:
        /// Create null-object
        object();

        /// Base virtual destructor
        virtual ~object();

        /// Copy-on-write from another object
        object(object const& another);

        /// Set object as specified value
        template <typename value_type>
        void set_as(value_type value);

        /// Get object as value of specified type
        template <typename value_type>
        value_type get_as() const;

        /// Initialize new data object by specified value
        template <typename value_type>
        object(value_type value);

        /// Initialize existing data object by specified value
        template <typename value_type>
        object& operator = (value_type value);

        /// Clone data into new object
        virtual object clone() const;

        /// Check is value
        virtual bool is_null() const;
    };

    DATA_API extern const object null;

//  data::object

    template <typename value_type>
    object::object(value_type value)
    {
        set_as(value);
    }

    template <typename value_type>
    object& object::operator = (value_type value)
    {
        set_as(value);
        return *this;
    }

    class text;

    template<> DATA_API void object::set_as(bool value);
    template<> DATA_API void object::set_as(int8_t value);
    template<> DATA_API void object::set_as(int16_t value);
    template<> DATA_API void object::set_as(int32_t value);
    template<> DATA_API void object::set_as(int64_t value);
    template<> DATA_API void object::set_as(uint8_t value);
    template<> DATA_API void object::set_as(uint16_t value);
    template<> DATA_API void object::set_as(uint32_t value);
    template<> DATA_API void object::set_as(uint64_t value);
    template<> DATA_API void object::set_as(float value);
    template<> DATA_API void object::set_as(double value);
    template<> DATA_API void object::set_as(text value);
    template<> DATA_API void object::set_as(const char* value);
    template<> DATA_API void object::set_as(const wchar_t* value);
    template<> DATA_API void object::set_as(std::nullptr_t value);

    template<> DATA_API bool object::get_as() const;
    template<> DATA_API int8_t object::get_as() const;
    template<> DATA_API int16_t object::get_as() const;
    template<> DATA_API int32_t object::get_as() const;
    template<> DATA_API int64_t object::get_as() const;
    template<> DATA_API uint8_t object::get_as() const;
    template<> DATA_API uint16_t object::get_as() const;
    template<> DATA_API uint32_t object::get_as() const;
    template<> DATA_API uint64_t object::get_as() const;
    template<> DATA_API float object::get_as() const;
    template<> DATA_API double object::get_as() const;
    template<> DATA_API text object::get_as() const;
    template<> DATA_API const char* object::get_as() const;
    template<> DATA_API const wchar_t* object::get_as() const;
}

// sine qua non
