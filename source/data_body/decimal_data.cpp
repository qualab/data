/// @author Владимир Керимов

#include <data_head/decimal_data.hpp>

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
}

// sine qua non
