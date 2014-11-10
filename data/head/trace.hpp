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
        auto_pop push(text const& info, text const& file, int line, text const& function);
        auto_pop push(char const* info, char const* file, int line, char const* function);

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
        entry(text const& info, text const& file, int line, text const& function);
        entry(char const* info, char const* file, int line, char const* function);

        text get_info() const;
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

#define DATA_CALL_INFO(information) \
    auto pop_back = trace::thread_stack().push(information, __FILE__, __LINE__, __FUNCTION__)

// sine qua non
