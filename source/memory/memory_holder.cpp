/// @author Владимир Керимов

#include <source/bytearray/bytearray_holder.hpp>

namespace data
{
    bytes::data::data()
    {
    }

    object::data* bytes::data::copy_to(void* address) const
    {
        return new(address) bytes::data(*this);
    }

    object::data* bytes::data::move_to(void* address) const
    {
        return new(address) bytes::data(std::move(*this));
    }
}

// sine qua non
