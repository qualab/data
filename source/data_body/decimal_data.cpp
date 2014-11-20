/// @author Владимир Керимов

#include <data_head/decimal_data.hpp>
#include <data/cast>

namespace data
{
    decimal::data::data()
        : m_integral(0), m_fractional(0)
    {
    }

    decimal::data::data(int64_t integral, uint64_t fractional)
        : m_integral(integral), m_fractional(fractional)
    {
    }

    decimal::data::data(double value)
        : m_integral(cast<int64_t>(value)), m_fractional(cast<uint64_t>((value - m_integral) * divider))
    {
    }

    decimal::data::data(float value)
        : m_integral(cast<int64_t>(value)), m_fractional(cast<uint64_t>((value - m_integral) * divider))
    {
    }

    decimal::data::data(text const& value)
        : m_integral(), m_fractional()
    {
        // TODO: ...
    }

    int64_t decimal::data::get_integral() const
    {
        return m_integral;
    }

    uint64_t decimal::data::get_fractional() const
    {
        return m_fractional;
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
        return cast<uint64_t>(m_integral);
    }

    int64_t decimal::data::as_int64() const
    {
        return m_integral;
    }

    double decimal::data::as_double() const
    {
        return cast<double>(m_integral) + m_fractional / static_cast<double>(divider);
    }

    float decimal::data::as_float() const
    {
        return cast<float>(m_integral) + m_fractional / static_cast<float>(divider);
    }

    text decimal::data::as_text() const
    {
        return text(); // TODO: ...
    }
}

// sine qua non
