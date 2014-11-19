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
        data(int64_t integral, uint64_t fractional);

        int64_t get_integral() const;
        uint64_t get_fractional() const;

        static const uint64_t divider = static_cast<int64_t>(1e+18);

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        /// Maximum of integer less than this value (floor)
		int64_t m_integral; 

        /// Fractional part multiplied to 10^18 and round to integer
        uint64_t m_fractional;
    };
}

// sine qua non
