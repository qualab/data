/// @author Владимир Керимов

#include <data_head/stacktrace_data.hpp>

#ifdef _MSC_VER
#define DATA_THREAD_LOCAL __declspec(thread)
#else
#define DATA_THREAD_LOCAL thread_local
#endif

namespace data
{
    namespace
    {
        DATA_THREAD_LOCAL stacktrace* g_thread_stack;
    }

    stacktrace::stacktrace()
        : object(m_data = new(buffer()) stacktrace::data)
    {
        static_assert(sizeof(stacktrace::data) <= data_max_size, "Data size of data::stacktrace class have greater size than provided by base data::object class.");
    }

#define DATA_stacktrace_ON_PUSH \
        if (m_data->is_on_push()) \
            return stacktrace::auto_pop(); \
        m_data->set_on_push(true) \

    stacktrace::auto_pop stacktrace::push(callinfo new_entry)
    {
        DATA_stacktrace_ON_PUSH;
        return m_data->push(new_entry);
    }

    stacktrace::auto_pop stacktrace::push(char const* info, char const* file, int line, char const* function)
    {
        DATA_stacktrace_ON_PUSH;
        return m_data->push(callinfo(info, file, line, function));
    }

    void stacktrace::pop()
    {
        m_data->pop();
        m_data->set_on_push(false);
    }

    stacktrace& stacktrace::thread_stack()
    {
        if (!g_thread_stack)
        {
            g_thread_stack = new stacktrace;
        }
        return *g_thread_stack;
    }

    callinfo stacktrace::operator [] (int index) const
    {
        return m_data->get_info(index);
    }

    callinfo stacktrace::get_info(int index) const
    {
        return m_data->get_info(index);
    }

    int stacktrace::get_length() const
    {
        return m_data->get_length();
    }

    callinfo::callinfo()
        : object(m_data = new(buffer()) callinfo::data)
    {
        static_assert(sizeof(callinfo::data) <= data_max_size, "Data size of data::callinfo class have greater size than provided by base data::object class.");
    }

    callinfo::callinfo(char const* info, char const* file, int line, char const* function)
        : object((m_data = new(buffer()) callinfo::data(info, file, line, function)))
    {
    }

    char const* callinfo::get_info() const
    {
        return m_data->get_info();
    }

    char const* callinfo::get_file() const
    {
        return m_data->get_file();
    }

    int callinfo::get_line() const
    {
        return m_data->get_line();
    }

    char const* callinfo::get_function() const
    {
        return m_data->get_function();
    }

    stacktrace::auto_pop::auto_pop()
        : m_stackstacktrace(nullptr)
    {
    }

    stacktrace::auto_pop::auto_pop(stacktrace* stackstacktrace)
        : m_stackstacktrace(stackstacktrace)
    {
    }

    stacktrace::auto_pop::auto_pop(stacktrace::auto_pop&& temporary)
        : m_stackstacktrace(nullptr)
    {
        std::swap(m_stackstacktrace, temporary.m_stackstacktrace);
    }

    stacktrace::auto_pop::~auto_pop()
    {
        if (m_stackstacktrace)
            m_stackstacktrace->pop();
    }
}

// sine qua non
