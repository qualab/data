/// @author Владимир Керимов

#pragma once

#include <data/object>
#include <data/nullable>

namespace data
{
    class DATA_API stacktrace : public object
    {
    public:
        stacktrace();

        class auto_pop;
        
        auto_pop push(callinfo new_call);
        auto_pop push(char const* info, char const* file, int line, char const* function);

        static stacktrace& thread_stack();

        callinfo operator [] (int index) const;
        callinfo get_info(int index) const;
        int get_length() const;

    protected:
        class holder;
        class instance;

        void pop();

    private:
        nullable<holder> m_holder;
    };
    
    class DATA_API callinfo : public object
    {
    public:
        callinfo();
        callinfo(char const* info, char const* file, int line, char const* function);

        char const* get_info() const;
        char const* get_file() const;
        int  get_line() const;
        char const* get_function() const;

    protected:
        class holder;

    private:
        nullable<holder> m_holder;
    };

    class DATA_API stacktrace::auto_pop
    {
    public:
        auto_pop();
        auto_pop(stacktrace* stackstacktrace);
        auto_pop(auto_pop&& temporary);
        ~auto_pop();

    private:
        stacktrace* m_stackstacktrace;

        auto_pop(auto_pop const&);
    };

    template<> DATA_API stacktrace object::as() const;
    template<> DATA_API callinfo object::as() const;
}

#define DATA_CALL_INFO(information) \
    auto pop_back = stacktrace::thread_stack().push(information, __FILE__, __LINE__, __FUNCTION__)

// sine qua non
