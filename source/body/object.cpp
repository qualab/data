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

    object::object(std::shared_ptr<object::data>&& prepared_data)
        : m_data(std::move(prepared_data))
    {
    }

    object::object(std::shared_ptr<object::data> const& data_reference)
        : m_data(data_reference)
    {
    }

    object::data const* object::get_data() const
    {
        return m_data.get();
    }

    object::data* object::get_data()
    {
        return m_data.get();
    }

    void object::set_data(std::shared_ptr<object::data>&& prepared_data)
    {
        m_data = std::move(prepared_data);
    }

    void object::set_data(std::shared_ptr<object::data> const& data_reference)
    {
        m_data = data_reference;
    }
}

// sine qua non
