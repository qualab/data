/// @author Владимир Керимов

#pragma once

#include <data/decimal>
#include <data_head/object_data.hpp>

namespace data
{
    class decimal::data : public object::data
    {
    public:
        data();
        data(int64_t intfloor, uint64_t multifract);

        data(int64_t value);
        data(double value);
        data(float value);
        data(text const& value);

        int64_t  get_intfloor() const;
        uint64_t get_multifract() const;

        static const uint64_t divider = static_cast<int64_t>(1e+18);

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

        virtual uint64_t as_uint64() const override;
        virtual int64_t  as_int64()  const override;

        virtual double as_double() const override;
        virtual float  as_float()  const override;

        virtual text as_text() const override;

    private:
		int64_t  m_intfloor;   //< maximal integer less than this value (floor)
        uint64_t m_multifract; //< fractional part multiplied to 10^18 and round to integer
    };
}

// sine qua non
