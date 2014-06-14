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

        /// Create object and initialize by specified value
        template <typename value_type>
        boolean(value_type value);

    protected:
        /// Forward declaration of boolean::data
        class data;

        /// Access to boolean::data class
        friend class object;
    };
    
    template <typename value_type>
    boolean::boolean(value_type value)
        : object(cast<bool>(value))
    {
    }
}

// sine qua non
