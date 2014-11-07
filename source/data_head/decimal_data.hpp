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

        int64_t intfloor() const;
        uint64_t multifract() const;

        static const uint64_t divider = static_cast<int64_t>(1e+18);

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
		int64_t  m_intfloor;   //< maximal integer less than this value (floor)
        uint64_t m_multifract; //< fractional part multiplied to 10^18 and round to integer
    };
}

// sine qua non
