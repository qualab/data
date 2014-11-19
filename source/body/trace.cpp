/// @author Владимир Керимов

#include <data_head/trace_data.hpp>

#ifdef _MSC_VER
#define DATA_THREAD_LOCAL __declspec(thread)
#else
#define DATA_THREAD_LOCAL thread_local
#endif

namespace data
{
    namespace
    {
        DATA_THREAD_LOCAL trace* g_thread_stack;
    }

    trace::trace()
        : object(m_data = new(buffer()) trace::data)
    {
        static_assert(sizeof(trace::data) <= data_max_size, "Data size of data::trace class have greater size than provided by base data::object class.");
    }

#define DATA_TRACE_ON_PUSH \
        if (m_data->is_on_push()) \
            return trace::auto_pop(); \
        m_data->set_on_push(true) \

    trace::auto_pop trace::push(trace::entry new_entry)
    {
        DATA_TRACE_ON_PUSH;
        return m_data->push(new_entry);
    }

    trace::auto_pop trace::push(text const& info, text const& file, int line, text const& function)
    {
        DATA_TRACE_ON_PUSH;
        return m_data->push(trace::entry(info, file, line, function));
    }

    trace::auto_pop trace::push(char const* info, char const* file, int line, char const* function)
    {
        DATA_TRACE_ON_PUSH;
        return m_data->push(trace::entry(info, file, line, function));
    }

    void trace::pop()
    {
        m_data->pop();
        m_data->set_on_push(false);
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
        return m_data->get_entry(index);
    }

    trace::entry trace::get_entry(int index) const
    {
        return m_data->get_entry(index);
    }

    int trace::get_entry_count() const
    {
        return m_data->get_entry_count();
    }

    trace::entry::entry()
        : object(m_data = new(buffer()) trace::entry::data)
    {
        static_assert(sizeof(trace::data) <= data_max_size, "Data size of data::trace::entry class have greater size than provided by base data::object class.");
    }

    trace::entry::entry(text const& info, text const& file, int line, text const& function)
        : object((m_data = new(buffer()) trace::entry::data(info, file, line, function)))
    {
    }

    trace::entry::entry(char const* info, char const* file, int line, char const* function)
        : object((m_data = new(buffer()) trace::entry::data(info, file, line, function)))
    {
    }

    text trace::entry::get_info() const
    {
        return m_data->get_info();
    }

    text trace::entry::get_file() const
    {
        return m_data->get_file();
    }

    int trace::entry::get_line() const
    {
        return m_data->get_line();
    }

    text trace::entry::get_function() const
    {
        return m_data->get_function();
    }

    trace::auto_pop::auto_pop()
        : m_stacktrace(nullptr)
    {
    }

    trace::auto_pop::auto_pop(trace* stacktrace)
        : m_stacktrace(stacktrace)
    {
    }

    trace::auto_pop::auto_pop(trace::auto_pop&& temporary)
        : m_stacktrace(nullptr)
    {
        std::swap(m_stacktrace, temporary.m_stacktrace);
    }

    trace::auto_pop::~auto_pop()
    {
        if (m_stacktrace)
            m_stacktrace->pop();
    }
}

// sine qua non
