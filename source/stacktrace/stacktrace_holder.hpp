/// @author Владимир Керимов

#pragma once

#include <data/stacktrace>
#include <data_head/object_data.hpp>
#include <data/text>
#include <deque>

namespace data
{
    class stacktrace::data : public object::data
    {
    public:
        data();

        auto_pop push(callinfo new_entry);
        void pop();

        bool is_on_push() const;
        void set_on_push(bool on_push);

        callinfo get_info(int index) const;
        int get_length() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        std::deque<callinfo> m_stack;
        bool m_on_push;
    };

    class callinfo::data : public object::data
    {
    public:
        data();
        data(char const* info, char const* file, int line, char const* function);

        virtual char const* get_info() const;
        virtual char const* get_file() const;
        virtual int get_line() const;
        virtual char const* get_function() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        char const* m_info;
        char const* m_file;
        int  m_line;
        char const* m_function;
    };
}

// sine qua non
