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

        text(char const* value);
        text(wchar_t const* value);

        /// Create object and initialize by specified value
        template <typename value_type>
        text(value_type value);

    protected:
        /// Forward declaration of text::data
        class data;
    };
    
    template <typename value_type>
    text::text(value_type value)
        : object(cast<text>(value))
    {
    }
}

// sine qua non
