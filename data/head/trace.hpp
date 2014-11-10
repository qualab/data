/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    class text;

    class DATA_API trace : public object
    {
    public:
        trace();

        class entry;
        class auto_pop;
        
        auto_pop push(entry new_entry);
        auto_pop push(text file, int line, text function);

        static trace& thread_stack();

        entry operator [] (int index) const;
        entry get_entry(int index) const;
        int get_entry_count() const;

    protected:
        class data;

        void pop();

    private:
        data* m_data;
    };
    
    class DATA_API trace::entry : public object
    {
    public:
        entry();
        entry(text file, int line, text function);
        
        text get_file() const;
        int  get_line() const;
        text get_function() const;

    protected:
        class data;

        friend class object;

    private:
        data* m_data;
    };

    class DATA_API trace::auto_pop
    {
    public:
        auto_pop();
        auto_pop(auto_pop&& temporary);
        ~auto_pop();

        friend class trace;

    private:
        bool m_need_pop;

        auto_pop(auto_pop const&);
    };

    template<> DATA_API trace object::as() const;
    template<> DATA_API trace::entry object::as() const;
}

#define DATA_TRACE_CALL(method) \
    auto pop_back = trace::thread_stack().push(__FILE__, __LINE__, __FUNCTION__); \
    return m_data->method

// sine qua non
