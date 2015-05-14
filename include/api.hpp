/// @author Владимир Керимов

#pragma once

#if !defined(WIN32) || defined(DATA_STATIC)
#   define DATA_API
#elif defined(DATA_EXPORTS)
#   define DATA_API __declspec(dllexport)
#else
#   define DATA_API __declspec(dllimport)
#endif

#define DATA_VERSION_MAJOR  0u
#define DATA_VERSION_MINOR  0u
#define DATA_SUBVERS_MAJOR  0u
#define DATA_SUBVERS_MINOR  0u

#define DATA_VERSION  ( (static_cast<unsigned>(DATA_VERSION_MAJOR) << 24) | \
                        (static_cast<unsigned>(DATA_VERSION_MINOR) << 16) | \
                        (static_cast<unsigned>(DATA_VERSION_MAJOR) <<  8) | \
                         static_cast<unsigned>(DATA_VERSION_MINOR) )

namespace data
{
    class object;
    class decimal;
    class text;
    class symbol;
    class stacktrace;
    class callinfo;
    class exception;
    class datetime;
    class date;
    class time;
    class timezone;
    class period;
    class month;
    class query;
    class unit;
    class iterator;
    class const_iterator;
}

// sine qua non
