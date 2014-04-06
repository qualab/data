/// @author Владимир Керимов

#include "trace_data.hpp"

namespace data
{
    trace::data::data()
    {
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
}

// sine qua non
