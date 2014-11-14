/// @author Владимир Керимов

#include <data_head/decimal_data.hpp>
#include <data/cast>

namespace data
{
    decimal::data::data()
        : m_intfloor(0), m_multifract(0)
    {
    }

    decimal::data::data(int64_t intfloor, uint64_t multifract)
        : m_intfloor(intfloor), m_multifract(multifract)
    {
    }

    decimal::data::data(int64_t value)
        : m_intfloor(value), m_multifract(0)
    {
    }

    decimal::data::data(double value)
        : m_intfloor(int(value)), m_multifract(int((value - m_intfloor) * divider))
    {
    }

    decimal::data::data(float value)
        : m_intfloor(int(value)), m_multifract(int((value - m_intfloor) * divider))
    {
    }

    decimal::data::data(text const& value)
        : m_intfloor(), m_multifract()
    {
        // TODO: read from text
    }

    int64_t decimal::data::get_intfloor() const
    {
        return m_intfloor;
    }

    uint64_t decimal::data::get_multifract() const
    {
        return m_multifract;
    }

    object::data* decimal::data::copy_to(void* address) const
    {
        return new(address) decimal::data(*this);
    }

    object::data* decimal::data::move_to(void* address) const
    {
        return new(address) decimal::data(std::move(*this));
    }

    uint64_t decimal::data::as_uint64() const
    {
        return cast<uint64_t>(m_intfloor);
    }

    int64_t decimal::data::as_int64() const
    {
        return m_intfloor;
    }

    double decimal::data::as_double() const
    {
        return cast<double>(m_intfloor) + m_multifract / static_cast<double>(divider);
    }

    float decimal::data::as_float() const
    {
        return cast<float>(m_intfloor) + m_multifract / static_cast<float>(divider);
    }

    text decimal::data::as_text() const
    {
        return text(); // TODO: ...
    }
}

// sine qua non
