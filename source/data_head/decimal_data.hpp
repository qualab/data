﻿/// @author Владимир Керимов

#pragma once

#include <data/decimal>
#include <data_head/object_data.hpp>

namespace data
{
    class decimal::data : public object::data
    {
    public:
        data();
        data(int64_t integral, uint64_t fractional);
        data(double value);
        data(float value);
        data(text const& value);

        int64_t get_integral() const;
        uint64_t get_fractional() const;

        static const uint64_t divider = static_cast<int64_t>(1e+18);

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

        virtual uint64_t as_uint64() const override;
        virtual int64_t  as_int64()  const override;

        virtual double as_double() const override;
        virtual float  as_float()  const override;

        virtual text as_text() const override;

    private:
        /// Maximum of integer less than this value (floor)
		int64_t m_integral; 

        /// Fractional part multiplied to 10^18 and round to integer
        uint64_t m_fractional;
    };
}

// sine qua non
