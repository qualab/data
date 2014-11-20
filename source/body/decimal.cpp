/// @author Владимир Керимов

#include <data_head/decimal_data.hpp>
#include <data/stacktrace>
#include <data/cast>
#include <data/cast>

namespace data
{
    decimal::decimal()
        DATA_OBJECT_CREATE(decimal::data, ())
    {
        DATA_CALL_INFO("Create data::decimal with zero value by default.");
        static_assert(sizeof(decimal::data) <= data_max_size, "Data size of data::decimal class have greater size than provided by base data::object class.");
    }

    decimal::decimal(text const& value)
        DATA_OBJECT_CREATE(decimal::data, (value))
    {
        DATA_CALL_INFO("Create data::decimal with value parsed from text.");
    }

    decimal::decimal(float value)
        DATA_OBJECT_CREATE(decimal::data, (value))
    {
        DATA_CALL_INFO("Create data::decimal with value of single-precision floating-point.");
    }

    decimal::decimal(double value)
        DATA_OBJECT_CREATE(decimal::data, (value))
    {
        DATA_CALL_INFO("Create data::decimal with value of double-precision floating-point.");
    }

    decimal::decimal(int64_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 64-bit signed integer.");
    }

    decimal::decimal(int32_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 32-bit signed integer.");
    }

    decimal::decimal(int16_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 16-bit signed integer.");
    }

    decimal::decimal(int8_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 8-bit signed integer.");
    }

    decimal::decimal(uint64_t value)
        DATA_OBJECT_CREATE(decimal::data, (cast<int64_t>(value), 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 64-bit unsigned integer.");
    }

    decimal::decimal(uint32_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 32-bit unsigned integer.");
    }

    decimal::decimal(uint16_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 16-bit unsigned integer.");
    }

    decimal::decimal(uint8_t value)
        DATA_OBJECT_CREATE(decimal::data, (value, 0))
    {
        DATA_CALL_INFO("Create data::decimal with value of 8-bit unsigned integer.");
    }

    decimal::decimal(int64_t integral, uint64_t fractional)
        : object(m_data = new(buffer()) decimal::data(integral, fractional))
    {
        DATA_CALL_INFO("Create data::decimal with value calculated by combining integral \"floor\" and fractional part muliplied to 10^18 and rounded to integer.");
    }

    int64_t decimal::get_integral() const
    {
        DATA_CALL_INFO("Get fractional part muliplied to 10^18 and rounded to integer.");
        return m_data->get_integral();
    }

    uint64_t decimal::get_fractional() const
    {
        DATA_CALL_INFO("Get maximal integer less than this value (integral \"floor\").");
        return m_data->get_fractional();
    }
}

// sine qua non
