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
        datetime(year const& the_year, month const& the_month, day const& the_day);

        /// Create datetime by date and time components
        datetime(year const& the_year, month const& the_month, day const& the_day,
                    int hour, int minute, decimal const& second);

        /// Create datetime by date and time components with time zone specified
        datetime(year const& the_year, month const& the_month, day const& the_day,
                    int hour, int minute, decimal const& second, timezone const& zone);

        /// Create datetime by date and time objects
        datetime(date const& the_date, time const& the_time);

        /// Create datetime by date
        datetime(date const& the_date);

        /// Create datetime by time of the current date
        datetime(time const& the_time);

        /// Get year from date
        year get_year() const;

        /// Get month from date
        month get_month() const;

        /// Get day from date
        day get_day() const;

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
        datetime operator + (period const& delta);

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

        /// Get year component
        year get_year() const;

        /// Get month component
        month get_month() const;

        /// Get day component
        day get_day() const;

        /// Add time interval to this data
        date& operator += (period const& delta);

        /// Addition of date and time interval
        datetime operator + (period const& delta);

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

        /// Create time zone with specified shift from UTC time
        timezone(decimal const& UTC_shift);

    protected:
        class data;

    private:
        data* m_data;
    };

    class DATA_API period : public object
    {
    public:
        period();

    protected:
        class data;

    private:
        data* m_data;
    };
}

// sine qua non
