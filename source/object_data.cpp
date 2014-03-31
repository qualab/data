/// @author Владимир Керимов

#include "object_data.hpp"
#include <stdexcept>

namespace data
{
    object::data::data()
    {
    }

    object::data::~data()
    {
    }

    bool object::data::is_null() const
    {
        return true;
    }

    int64_t object::data::get_as_int64() const
    {
        throw std::runtime_error("Unable to get null-value as integer.");
    }

    double object::data::get_as_double() const
    {
        throw std::runtime_error("Unable to get null-value as floating point.");
    }

    bool object::data::get_as_bool() const
    {
        return false;
    }
}

// sine qua non
