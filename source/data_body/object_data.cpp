/// @author Владимир Керимов

#include <data_head/object_data.hpp>

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

    std::shared_ptr<object::data> object::data::clone() const
    {
        return std::make_shared<object::data>(*this);
    }
}

// sine qua non
