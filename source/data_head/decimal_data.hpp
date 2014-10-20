/// @author Владимир Керимов

#pragma once

#include <data/floating>
#include <data_head/object_data.hpp>

namespace data
{
    class floating::data : public object::data
    {
    public:
        data();
		data(double value);
		
		void set_value(double value);
		double get_value() const;

    private:
		double m_value;
    };
}

// sine qua non
