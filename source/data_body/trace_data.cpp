/// @author Владимир Керимов

#include "trace_data.hpp"

namespace data
{
    trace::data::data()
    {
    }

    trace::auto_pop trace::data::push(trace::entry new_entry)
    {
        m_entries.push_back(new_entry);
        return auto_pop();
    }

    void trace::data::pop()
    {
        m_entries.pop_back();
    }

    trace::entry trace::data::get_entry(int index) const
    {
        return m_entries.at(index);
    }

    int trace::data::get_entry_count() const
    {
        return m_entries.size();
    }

    bool trace::data::is_null() const
    {
        return false;
    }

    trace::entry::data::data()
    {
    }

    trace::entry::data::data(text file, int line, text function)
        : m_file(file), m_line(line), m_function(function)
    {
    }

    text trace::entry::data::get_file() const
    {
        return m_file;
    }

    int trace::entry::data::get_line() const
    {
        return m_line.get_as<int>();
    }

    text trace::entry::data::get_function() const
    {
        return m_function;
    }

    bool trace::entry::data::is_null() const
    {
        return false;
    }

    trace::auto_pop::data::data()
    {
    }

    trace::auto_pop::data::data(trace& target)
        : m_target(&target)
    {
    }

    trace::auto_pop::data::~data()
    {
        if (m_target)
            m_target->pop();
    }
}

// sine qua non
