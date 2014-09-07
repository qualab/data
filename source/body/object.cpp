/// @author Владимир Керимов

#include <data_head/object_data.hpp>
#include <data_head/boolean_data.hpp>
#include <data_head/floating_data.hpp>
#include <data_head/integer_data.hpp>
#include <data_head/text_data.hpp>
#include <data/trace>
#include <data/cast>

namespace data
{
    const object null;

    object::object()
    {
    }

    object::~object()
    {
    }

    object object::clone() const
    {
        return object(m_data->clone());
    }

    object object::reference() const
    {
        return object(m_data);
    }

    bool object::is_null() const
    {
        DATA_TRACE_CALL(is_null)();
    }

    object::data const* object::get_data() const
    {
        return m_data.get();
    }

    object::data* object::get_data()
    {
        return m_data.get();
    }

    template<>
    int64_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)();
    }

    template<>
    uint64_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    int32_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    uint32_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    int16_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    uint16_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    int8_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    uint8_t object::get_as() const
    {
        DATA_TRACE_CALL(get_as_int64)(); /// TODO: safe cast
    }

    template<>
    double object::get_as() const
    {
        DATA_TRACE_CALL(get_as_double)();
    }

    template<>
    float object::get_as() const
    {
        DATA_TRACE_CALL(get_as_double)(); /// TODO: safe cast
    }

    template<>
    bool object::get_as() const
    {
        DATA_TRACE_CALL(get_as_bool)();
    }

    template<>
    text object::get_as() const
    {
        DATA_TRACE_CALL(get_as_text)(); /// TODO: object get as text
    }
}

// sine qua non
