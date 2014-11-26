/// @author Владимир Керимов

#include <data_head/bytes_data.hpp>
#include <data/stacktrace>

namespace data
{
    bytes::bytes()
        DATA_OBJECT_CREATE(bytes::data, ())
    {
        DATA_CALL_INFO("Create an empty data::bytes object with text of zero length.");
        static_assert(sizeof(bytes::data) <= data_max_size, "Data size of data::bytes class have greater size than provided by base data::object class.");
    }
}

// sine qua non
