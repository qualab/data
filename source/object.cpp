/// @author Владимир Керимов

#include "object_data.hpp"
#include "boolean_data.hpp"
#include "floating_data.hpp"
#include "integer_data.hpp"
#include "text_data.hpp"
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
        return object(m_data.clone());
    }

    bool object::is_null() const
    {
        DATA_TRACE_CALL(m_data, is_null)();
    }

    object::object(object::data* new_data)
        : m_data(new_data)
    {
    }

    object::object(lazy<object::data> const& prepared_data)
        : m_data(prepared_data)
    {
    }

    template<>
    int64_t object::get_as() const
    {
        return m_data->get_as_int64();
    }

    template<>
    uint64_t object::get_as() const
    {
        return cast<uint64_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    int32_t object::get_as() const
    {
        return cast<int32_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    uint32_t object::get_as() const
    {
        return cast<uint32_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    int16_t object::get_as() const
    {
        return cast<int16_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    uint16_t object::get_as() const
    {
        return cast<uint16_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    int8_t object::get_as() const
    {
        return cast<int8_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    uint8_t object::get_as() const
    {
        return cast<uint8_t>(m_data->get_as_int64()); /// TODO: safe cast
    }

    template<>
    double object::get_as() const
    {
        return m_data->get_as_double();
    }

    template<>
    float object::get_as() const
    {
        return cast<float>(m_data->get_as_double()); /// TODO: safe cast
    }

    template<>
    bool object::get_as() const
    {
        return m_data->get_as_bool();
    }

    template<>
    text object::get_as() const
    {
        return m_data->get_as_text(); /// TODO: object get as text
    }
}

// sine qua non
