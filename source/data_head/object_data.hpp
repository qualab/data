/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <memory>

namespace data
{
    // base class for data of object
    class object::data
    {
    public:
        // create null object
        data();

        // destruct data
        virtual ~data();

        // clone data of object into the new object
        virtual object clone() const = 0;

        // copy data of object into the buffer specified
        virtual data* copy_to(void* address) const = 0;

        // move data of object into the buffer specified
        virtual data* move_to(void* address) const = 0;
    };


    template <typename value_type>
    class scalar_data : public object::data
    {
    public:
        scalar_data(value_type value)
            : m_value(value) {
        }

        value_type value() const {
            return m_value;
        }

        virtual object clone() const override {
            return object(scalar_data(*this));
        }

        virtual data* copy_to(void* address) const override {
            return new(address) scalar_data(*this);
        }

        virtual data* move_to(void* address) const override {
            return new(address) scalar_data(std::move(*this));
        }

    private:
        value_type m_value;
    };
}

// sine qua non
