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

        /// Create object and initialize by specified value
        template <typename value_type>
        boolean(value_type value);

    protected:
        /// Forward declaration of boolean::data
        class data;

        /// Initialize boolean by prepared data
        boolean(std::shared_ptr<data>&& prepared_data);

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
