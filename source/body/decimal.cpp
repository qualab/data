/// @author Владимир Керимов

#include <data_head/decimal_data.hpp>

namespace data
{
    decimal::decimal()
        : object((m_data = new(buffer()) decimal::data))
    {
    }

    decimal::decimal(text const& value)
    {
        // TODO: ...
    }

    decimal::decimal(float value)
    {
        // TODO: ...
    }

    decimal::decimal(double value)
    {
        // TODO: ...
    }

    decimal::decimal(int64_t value)
    {
        // TODO: ...
    }

    decimal::decimal(int32_t value)
    {
        // TODO: ...
    }

    decimal::decimal(int16_t value)
    {
        // TODO: ...
    }

    decimal::decimal(int8_t value)
    {
        // TODO: ...
    }

    decimal::decimal(uint64_t value)
    {
        // TODO: ...
    }

    decimal::decimal(uint32_t value)
    {
        // TODO: ...
    }

    decimal::decimal(uint16_t value)
    {
        // TODO: ...
    }

    decimal::decimal(uint8_t value)
    {
        // TODO: ...
    }

    decimal::decimal(int64_t integral, uint64_t fractional)
        : object((m_data = new(buffer()) decimal::data(integral, fractional)))
    {
    }

    int64_t decimal::intfloor() const
    {
        return m_data->intfloor();
    }

    uint64_t decimal::multifract() const
    {
        return m_data->multifract();
    }
}

// sine qua non
