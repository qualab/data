﻿/// @author Владимир Керимов

#pragma once

#include <data/api>
#include <data/lazy>
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

        /// Base virtual destructor
        virtual ~object();

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

        /// Create object refers to the same data
        virtual object reference() const;

        /// Check is value equal to null
        virtual bool is_null() const;

    protected:
        /// Base object data class
        class data;

        /// Initialization by new created data
        object(data* new_data);

        /// Initialization by prepared data
        object(lazy<data> const& prepared_data);

        /// Initialization by same data as in referenced object
        object(std::shared_ptr<lazy<data>> referenced_data);

        /// Ensure that data reference is initialized
        virtual void ensure_initialized() const;

        /// Initialize data reference
        virtual void initialize() const;

        /// Get lazy data const-reference
        virtual lazy<data> const& get_lazy_data() const;

        /// Get lazy data reference
        virtual lazy<data>& get_lazy_data();

        /// Set lazy data reference by new lazy<data>
        virtual void set_lazy_data(lazy<data>* new_lazy_data) const;

    private:
        /// Reference to the data with lazy behavior
        mutable std::shared_ptr<lazy<data>> m_data;
    };

    /// Representation of null constant
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
    template<> DATA_API void object::set_as(char const* value);
    template<> DATA_API void object::set_as(wchar_t const* value);
    template<> DATA_API void object::set_as(std::string const& value);
    template<> DATA_API void object::set_as(std::wstring const& value);
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
    template<> DATA_API char const* object::get_as() const;
    template<> DATA_API wchar_t const* object::get_as() const;
    template<> DATA_API std::string object::get_as() const;
    template<> DATA_API std::wstring object::get_as() const;
}

// sine qua non
