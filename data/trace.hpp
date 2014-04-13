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

    private:
        class data;

        void pop();

        data& get_data();
        data const& get_data() const;
    };
    
    class DATA_API trace::entry : public object
    {
    public:
        entry();
        entry(text file, int line, text function);
        
        text get_file() const;
        int get_line() const;
        text get_function() const;

    private:
        class data;

        friend class object;

        data& get_data();
        data const& get_data() const;
    };

    class DATA_API trace::auto_pop : public object
    {
    private:
        class data;

        auto_pop();

        friend class trace;
    };

    template<> DATA_API void object::set_as(trace value);
    template<> DATA_API void object::set_as(trace::entry value);

    template<> DATA_API trace object::get_as() const;
    template<> DATA_API trace::entry object::get_as() const;
}

// sine qua non
