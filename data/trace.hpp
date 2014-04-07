/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    class text;

    class trace : public object
    {
    public:
        trace();

        class entry;
        
        entry push(text file, int line, text function);

        static trace& thread_stack();

        entry operator [] (int index) const;
        entry get_entry(int index) const;

    private:
        class data;
    };
    
    class trace::entry : public object
    {
    public:
        entry();
        entry(trace& owner, text file, int line, text function);
        
        text get_file() const;
        int get_line() const;
        text get_function() const;

    private:
        class data;
    };
}

// sine qua non
