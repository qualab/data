/// @author Владимир Керимов

#include "trace_data.hpp"

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

    trace::data& trace::get_data()
    {
        return (*m_data)->get_data_as<trace::data>();
    }

    trace::data const& trace::get_data() const
    {
        return (*m_data)->get_data_as<trace::data>();
    }

    trace::auto_pop trace::push(trace::entry new_entry)
    {
        return get_data().push(new_entry);
    }

    trace::auto_pop trace::push(text file, int line, text function)
    {
        return get_data().push(entry(file, line, function));
    }

    void trace::pop()
    {
        get_data().pop();
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
        return get_data().get_entry(index);
    }

    trace::entry trace::get_entry(int index) const
    {
        return get_data().get_entry(index);
    }

    int trace::get_entry_count() const
    {
        return get_data().get_entry_count();
    }

    trace::entry::entry()
    {
    }

    trace::entry::entry(text file, int line, text function)
        : object(static_cast<object::data*>(new trace::entry::data(file, line, function)))
    {
    }

    trace::entry::data& trace::entry::get_data()
    {
        return (*m_data)->get_data_as<trace::entry::data>();
    }

    trace::entry::data const& trace::entry::get_data() const
    {
        return (*m_data)->get_data_as<trace::entry::data>();
    }

    text trace::entry::get_file() const
    {
        return get_data().get_file();
    }

    int trace::entry::get_line() const
    {
        return get_data().get_line();
    }

    text trace::entry::get_function() const
    {
        return get_data().get_function();
    }

    trace::auto_pop::auto_pop()
        : object(static_cast<object::data*>(new trace::auto_pop::data))
    {
    }
}

// sine qua non
