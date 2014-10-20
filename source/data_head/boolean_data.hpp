/// @author Владимир Керимов

#pragma once

#include <data/boolean>
#include <data_head/object_data.hpp>

namespace data
{
    // data of boolean object
    class boolean::data : public object::data
    {
    public:
        // initialixe data by bool
        data(bool value);

        // boolean data is not null
        virtual bool is_null() const override;

        // clone boolean data
        virtual std::shared_ptr<object::data> clone() const override;

        // get boolean data as bool
        virtual bool get_value() const;

        // set boolean data by bool
        virtual void set_value(bool value);

    private:
        // bool value
        bool m_value;
    };
}

// sine qua non
