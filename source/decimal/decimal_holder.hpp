/// @author Владимир Керимов

#pragma once

#include <data/decimal>
#include <object/object_holder.hpp>

namespace data
{
    class decimal::holder : public object::holder
    {
    public:
        holder();
        holder(int64_t integral, uint64_t fractional);
        holder(double value);
        holder(float value);
        holder(text const& value);

        int64_t get_integral() const;
        uint64_t get_fractional() const;

        static const uint64_t divider = static_cast<int64_t>(1e+18);

        virtual object::holder* copy_to(void* address) const override;
        virtual object::holder* move_to(void* address) const override;

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
