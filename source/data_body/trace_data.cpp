﻿/// @author Владимир Керимов

#include <data_head/trace_data.hpp>

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

    bool trace::data::is_on_push() const
    {
        return m_on_push;
    }

    void trace::data::set_on_push(bool on_push)
    {
        m_on_push = on_push;
    }

    trace::entry trace::data::get_entry(int index) const
    {
        return m_entries.at(index);
    }

    int trace::data::get_entry_count() const
    {
        return m_entries.size();
    }

    object::data* trace::data::copy_to(void* address) const
    {
        return new(address) trace::data(*this);
    }

    object::data* trace::data::move_to(void* address) const
    {
        return new(address) trace::data(std::move(*this));
    }

    trace::entry::data::data()
    {
    }

    trace::entry::data::data(char const* info, char const* file, int line, char const* function)
        : m_info(info), m_file(file), m_line(line), m_function(function)
    {
    }

    char const* trace::entry::data::get_info() const
    {
        return m_info;
    }

    char const* trace::entry::data::get_file() const
    {
        return m_file;
    }

    int trace::entry::data::get_line() const
    {
        return m_line;
    }

    char const* trace::entry::data::get_function() const
    {
        return m_function;
    }

    object::data* trace::entry::data::copy_to(void* address) const
    {
        return new(address) trace::entry::data(*this);
    }

    object::data* trace::entry::data::move_to(void* address) const
    {
        return new(address) trace::entry::data(std::move(*this));
    }
}

// sine qua non
