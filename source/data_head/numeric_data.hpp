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
        virtual bool is_null() const override;
        double get_value() const;

        virtual double get_as_double() const override;
        virtual bool get_as_bool() const override;

    private:
        double m_value;
    };
}

// sine qua non
