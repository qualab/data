﻿/// @author Владимир Керимов

#include <data_head/trace_data.hpp>

#ifdef WIN32
#define DATA_THREAD_LOCAL __declspec(thread)
#else
#define DATA_THREAD_LOCAL 
#endif

namespace data
{
    namespace
    {
        DATA_THREAD_LOCAL trace* g_thread_stack;
    }

    trace::trace()
    {
    }

    trace::auto_pop trace::push(trace::entry new_entry)
    {
        DATA_TRACE_CALL(push)(new_entry);
    }

    trace::auto_pop trace::push(text file, int line, text function)
    {
        DATA_TRACE_CALL(push)(entry(file, line, function));
    }

    void trace::pop()
    {
        DATA_TRACE_CALL(pop)();
    }

    trace& trace::thread_stack()
    {
        if (!g_thread_stack)
        {
            g_thread_stack = new trace;
        }
        return *g_thread_stack;
    }

    trace::entry trace::operator [] (int index) const
    {
        DATA_TRACE_CALL(get_entry)(index);
    }

    trace::entry trace::get_entry(int index) const
    {
        DATA_TRACE_CALL(get_entry)(index);
    }

    int trace::get_entry_count() const
    {
        DATA_TRACE_CALL(get_entry_count)();
    }

    trace::entry::entry()
    {
    }

    trace::entry::entry(text file, int line, text function)
        : object(std::shared_ptr<object::data>((m_data = new trace::entry::data(file, line, function))))
    {
    }

    text trace::entry::get_file() const
    {
        DATA_TRACE_CALL(get_file)();
    }

    int trace::entry::get_line() const
    {
        DATA_TRACE_CALL(get_line)();
    }

    text trace::entry::get_function() const
    {
        DATA_TRACE_CALL(get_function)();
    }

    trace::auto_pop::auto_pop()
        : object(std::shared_ptr<object::data>(m_data = new trace::auto_pop::data))
    {
    }
}

// sine qua non
