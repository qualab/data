/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/stdfwd>

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
        text(std::string const& value);
        text(std::wstring const& value);

        text(object const& another);

    protected:
        /// Forward declaration of text::data
        class data;

    private:
        data* m_data;
    };
}

// sine qua non
