/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type for textual data
    class DATA_API text : public object
    {
    public:
        /// Create null-object of no text
        text();

        /// Create object and initialize by specified value
        template <typename value_type>
        text(value_type value);

        /// Clone data into new object
        virtual object clone() const;

        /// Check is value
        virtual bool is_null() const;

    protected:
        /// Forward declaration of text::data
        class data;

        /// Create text by prepared data
        text(lazy<data> const& data);

    private:
        /// Object data is lazy to initialize and copy-on-write
        lazy<data> m_data;
    };
    
    template <typename value_type>
    text::text(value_type value)
        : object(value)
    {
    }
}

// sine qua non
