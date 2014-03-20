/// @author Владимир Керимов

#pragma once

#include <data/api>
#include <data/lazy>

namespace data
{
    /// Base type for any other
    class DATA_API object
    {
    public:
        /// Create null-object
        object();

    protected:
        /// Forward declaration of object::data
        class data;

    private:
        /// Object data is lazy to initialize and copy-on-write
        lazy<data> m_data;
    };
}

// sine qua non