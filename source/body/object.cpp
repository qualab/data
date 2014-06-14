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

    object::object(object::data* new_data)
        : m_data(new lazy<object::data>(new_data))
    {
    }

    object::object(lazy<object::data> const& prepared_data)
        : m_data(new lazy<object::data>(prepared_data))
    {
    }

    object::object(std::shared_ptr<lazy<object::data>> referenced_data)
        : m_data(referenced_data)
    {
    }

    void object::ensure_initialized() const
    {
        if (!m_data)
            initialize();
    }

    void object::initialize() const
    {
        set_lazy_data(new lazy<object::data>);
    }

    lazy<object::data> const& object::get_lazy_data() const
    {
        ensure_initialized();
        return *m_data;
    }

    lazy<object::data>& object::get_lazy_data()
    {
        ensure_initialized();
        return *m_data;
    }

    void object::set_lazy_data(lazy<object::data>* new_lazy_data) const
    {
        m_data.reset(new_lazy_data);
    }

    lazy<object::data> const& object::get_data() const
    {
        return get_lazy_data();
    }

    lazy<object::data>& object::get_data()
    {
        return get_lazy_data();
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
