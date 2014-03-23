/// @author Владимир Керимов

#pragma once

#include <data/object>

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

        /// Clone data into new object
        virtual object clone() const override;

    protected:
        /// Forward declaration of object::data
        class data;

        /// Initialize boolean by prepared data
        boolean(data* new_data);

    private:
        /// Object data is lazy to initialize and copy-on-write
        lazy<data> m_data;
    };
    
    template <typename value_type>
    boolean::boolean(value_type value)
        : object(value)
    {
    }
}

// sine qua non
