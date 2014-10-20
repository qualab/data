/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/lazy>
#include <data/cast>

namespace data
{
    /// Type for boolean logic
    class DATA_API boolean : public object
    {
    public:
        /// Create null-object of not initialized boolean
        boolean();

        /// Create boolean object initialized as true or false
        boolean(bool value);

        /// Create boolean object initialized as null
        boolean(std::nullptr_t);

        boolean(boolean const& another);
        boolean(object const& another);

        boolean& operator = (boolean const& another);
        boolean& operator = (object const& another);

        /// Create object and initialize by specified value
        template <typename value_type>
        boolean(value_type value);

        /// Set boolean value
        void set_value(bool value);

        /// Get boolean value
        bool get_value() const;

    protected:
        /// Forward declaration of boolean::data
        class data;

        /// Access to boolean::data class
        friend class object;

    private:
        data* m_data;
    };
    
    template <typename value_type>
    boolean::boolean(value_type value)
    {
        set_as(cast<bool>(value));
    }
}

// sine qua non
