/// @author Владимир Керимов

#pragma once

#include <data/trace>
#include <data_head/object_data.hpp>
#include <data/text>
#include <deque>

namespace data
{
    class trace::data : public object::data
    {
    public:
        data();

        auto_pop push(trace::entry new_entry);
        void pop();

        bool is_on_push() const;
        void set_on_push(bool on_push);

        entry get_entry(int index) const;
        int get_entry_count() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        std::deque<trace::entry> m_entries;
        bool m_on_push;
    };

    class trace::entry::data : public object::data
    {
    public:
        data();
        data(text const& info, text const& file, int line, text const& function);

        virtual text get_info() const;
        virtual text get_file() const;
        virtual int  get_line() const;
        virtual text get_function() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        text m_info;
        text m_file;
        int  m_line;
        text m_function;
    };
}

// sine qua non
