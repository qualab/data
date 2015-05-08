/// @author Владимир Керимов

#pragma once

#include <data/object>

namespace data
{
    /// Type of date and time with time zone
    class DATA_API datetime : public object
    {
    public:
        /// Create datetime of null value
        datetime();

        /// Create datetime of current moment
        static datetime now();

        /// Create datetime by date components
        datetime(int the_year, month const& the_month, int the_day);

        /// Create datetime by date and time components
        datetime(int the_year, month const& the_month, int the_day,
                    int hour, int minute, decimal const& second);

        /// Create datetime by date and time components with time zone specified
        datetime(int the_year, month const& the_month, int the_day,
                    int hour, int minute, decimal const& second, timezone const& zone);

        /// Create datetime by date and time objects
        datetime(date const& the_date, time const& the_time);

        /// Create datetime by date
        datetime(date const& the_date);

        /// Create datetime by time of the current date
        datetime(time const& the_time);

        /// Get year from date
        int get_year() const;

        /// Get month from date
        month get_month() const;

        /// Get day from date
        int get_day() const;

        /// Get hour from time
        int get_hour() const;

        /// Get minute from time
        int get_minute() const;

        /// Get second from time
        decimal get_second() const;

        /// Get timezone specified
        timezone get_timezone() const;

        /// Get date component
        date get_date() const;

        /// Get time component
        time get_time() const;

        /// Add time interval to this datetime point
        datetime& operator += (period const& delta);

        /// Addition of datetime point and time interval
        datetime operator + (period const& delta) const;

        /// Subtraction between two datetime points
        period operator - (datetime const& another);

    protected:
        /// Forward declaration of datetime::data
        class data;

    private:
        /// Stored pointer to datetime::data
        data* m_data;
    };

    /// Type of gregorian date
    class DATA_API date : public object
    {
    public:
        /// Create date with null-value
        date();

        /// Create date of current moment
        static date now();

        /// Create date by year, month and day specified
        date(int year, int month, int day);

        /// Create date by component of date in datetime
        date(datetime const& the_datetime);

        /// Get component of years
        int get_year() const;

        /// Get component of months
        month get_month() const;

        /// Get component of days
        int get_day() const;

        /// Add time interval to this data
        date& operator += (period const& delta);

        /// Addition of date and time interval
        datetime operator + (period const& delta) const;

        /// Subtraction between two dates
        period operator - (date const& another);

    protected:
        /// Forward declaration of date::data
        class data;

    private:
        /// Stored pointer to date::data
        data* m_data;
    };

    /// Type of time with optional time zone
    class DATA_API time : public object
    {
    public:
        /// Create time with null-value
        time();

        /// Create time of current moment
        static time now();

        /// Create time by hour, minute and second components
        time(int hour, int minute, decimal const& second);

        /// Create time by hour, minute and second components with time zone
        time(int hour, int minute, decimal const& second, timezone const& zone);

        /// Create time by time component of datetime
        time(datetime const& the_datetime);

        /// Get component of hours
        int get_hour() const;

        /// Get component of minutes
        int get_minute() const;

        /// Get component of seconds
        decimal get_second() const;

        /// Get time zone specified
        timezone get_timezone() const;

        time& operator += (period const& delta);

        time operator + (period const& delta) const;

    protected:
        /// Forward declaration of time::data
        class data;

    private:
        /// Stored pointer to time::data
        data* m_data;
    };

    /// Time zone of time specified
    class DATA_API timezone : public object
    {
    public:
        /// Create time zone of null value (no time zone specified)
        timezone();

        /// Create time zone by specified time shift in hours from UTC time
        timezone(decimal const& shift);

        /// Create time zone by name
        timezone(text const& name);

        /// Get time shift in hours from UTC time
        decimal get_shift();

        text get_name() const;

    protected:
        /// Forward declaration of timezone::data
        class data;

    private:
        /// Stored pointer to timezone::data
        data* m_data;
    };

    /// Period of time between two date and/or time points
    class DATA_API period : public object
    {
    public:
        /// Create period of zero length
        period();

        /// Create period of specified length in seconds
        period(decimal const& seconds);

        /// Get specified length in seconds of this period of time
        decimal get_length();

    protected:
        /// Forward declaration of period::data
        class data;

    private:
        /// Stored pointer to period::data
        data* m_data;
    };

    /// Month with ability to create month by name or number
    class DATA_API month
    {
    public:
        /// Enumerate months by name
        enum name
        {
            January   =  1,
            Febrary   =  2,
            March     =  3,
            April     =  4,
            May       =  5,
            June      =  6,
            July      =  7,
            August    =  8,
            September =  9,
            October   = 10,
            November  = 11,
            December  = 12,
            Unknown   =  0
        };

        /// Create month of unknown value
        month();

        /// Create month by value of name enumeration
        month(name the_name);

        /// Create month by number in year, January is first and equal to 1
        month(int number);

        /// Create month by textual name
        month(text const& the_name);

        /// Get number of month in the year, starts from 1 for January
        int get_number() const;

        /// Implicitely cast month to the integral value of number in the year
        operator int () const;

        /// Get name of month
        text get_name() const;

    private:
        /// Numeration starts from 1 for January
        int m_number;
    };
}

// sine qua non
