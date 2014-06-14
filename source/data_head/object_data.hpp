/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    class object::data
    {
    public:
        data();
        virtual ~data();
        virtual bool is_null() const;

        virtual int64_t get_as_int64() const;
        virtual double get_as_double() const;
        virtual bool get_as_bool() const;
        virtual text get_as_text() const;

        template <class derived_data_type>
        derived_data_type const& get_data_as() const
        {
            return dynamic_cast<derived_data_type const&>(*this);
        }

        template <class derived_data_type>
        derived_data_type& get_data_as()
        {
            return dynamic_cast<derived_data_type&>(*this);
        }
    };
}

// sine qua non
