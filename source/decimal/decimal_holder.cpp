/// @author Владимир Керимов

#include <decimal/decimal_holder.hpp>
#include <data/cast>

namespace data
{
    decimal::holder::holder()
        : m_integral(0), m_fractional(0)
    {
    }

    decimal::holder::holder(int64_t integral, uint64_t fractional)
        : m_integral(integral), m_fractional(fractional)
    {
    }

    decimal::holder::holder(double value)
        : m_integral(cast<int64_t>(value)), m_fractional(cast<uint64_t>((value - m_integral) * divider))
    {
    }

    decimal::holder::holder(float value)
        : m_integral(cast<int64_t>(value)), m_fractional(cast<uint64_t>((value - m_integral) * divider))
    {
    }

    decimal::holder::holder(text const& value)
        : m_integral(), m_fractional()
    {
        // TODO: ...
    }

    int64_t decimal::holder::get_integral() const
    {
        return m_integral;
    }

    uint64_t decimal::holder::get_fractional() const
    {
        return m_fractional;
    }

    object::holder* decimal::holder::copy_to(void* address) const
    {
        return new(address) decimal::holder(*this);
    }

    object::holder* decimal::holder::move_to(void* address) const
    {
        return new(address) decimal::holder(std::move(*this));
    }

    uint64_t decimal::holder::as_uint64() const
    {
        return cast<uint64_t>(m_integral);
    }

    int64_t decimal::holder::as_int64() const
    {
        return m_integral;
    }

    double decimal::holder::as_double() const
    {
        return cast<double>(m_integral) + m_fractional / static_cast<double>(divider);
    }

    float decimal::holder::as_float() const
    {
        return cast<float>(m_integral) + m_fractional / static_cast<float>(divider);
    }

    text decimal::holder::as_text() const
    {
        return text(); // TODO: ...
    }
}

// sine qua non
