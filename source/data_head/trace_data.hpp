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

        entry get_entry(int index) const;
        int get_entry_count() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        std::deque<trace::entry> m_entries;
    };

    class trace::entry::data : public object::data
    {
    public:
        data();
        data(text file, int line, text function);

        virtual text get_file() const;
        virtual int  get_line() const;
        virtual text get_function() const;

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        text m_file;
        int m_line;
        text m_function;
    };

    class trace::auto_pop::data : public object::data
    {
    public:
        data();
        data(trace& target);

        virtual ~data();

        virtual object::data* copy_to(void* address) const override;
        virtual object::data* move_to(void* address) const override;

    private:
        trace* m_target;
    };
}

// sine qua non
