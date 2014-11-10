/// @author Владимир Керимов

#include <data_head/decimal_data.hpp>

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
}

// sine qua non
