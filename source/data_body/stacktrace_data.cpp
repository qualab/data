/// @author Владимир Керимов

#include <data_head/stacktrace_data.hpp>

namespace data
{
    stacktrace::data::data()
    {
    }

    stacktrace::auto_pop stacktrace::data::push(callinfo new_entry)
    {
        m_stack.push_back(new_entry);
        return auto_pop();
    }

    void stacktrace::data::pop()
    {
        m_stack.pop_back();
    }

    bool stacktrace::data::is_on_push() const
    {
        return m_on_push;
    }

    void stacktrace::data::set_on_push(bool on_push)
    {
        m_on_push = on_push;
    }

    callinfo stacktrace::data::get_info(int index) const
    {
        return m_stack.at(index);
    }

    int stacktrace::data::get_length() const
    {
        return m_stack.size();
    }

    object::data* stacktrace::data::copy_to(void* address) const
    {
        return new(address) stacktrace::data(*this);
    }

    object::data* stacktrace::data::move_to(void* address) const
    {
        return new(address) stacktrace::data(std::move(*this));
    }

    callinfo::data::data()
    {
    }

    callinfo::data::data(char const* info, char const* file, int line, char const* function)
        : m_info(info), m_file(file), m_line(line), m_function(function)
    {
    }

    char const* callinfo::data::get_info() const
    {
        return m_info;
    }

    char const* callinfo::data::get_file() const
    {
        return m_file;
    }

    int callinfo::data::get_line() const
    {
        return m_line;
    }

    char const* callinfo::data::get_function() const
    {
        return m_function;
    }

    object::data* callinfo::data::copy_to(void* address) const
    {
        return new(address) callinfo::data(*this);
    }

    object::data* callinfo::data::move_to(void* address) const
    {
        return new(address) callinfo::data(std::move(*this));
    }
}

// sine qua non
