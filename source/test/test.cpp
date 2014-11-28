/// @author Владимир Керимов

#include "test.hpp"
#include <functional>
#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include <conio.h>

namespace
{
    void press_any_key()
    {
        std::cout << "\nPress any key... ";
        _getch();
    }
}


int main()
{
    using data::test::application;
    std::atexit(press_any_key);
    application::instance().run();
    return 0;
}


namespace data
{
    namespace test
    {
        scope::scope(std::string const& name, bool add_to_application)
            : m_name(name)
        {
            if (add_to_application)
            {
                application::instance().add_test(*this);
            }
        }

        void scope::add_test(test_functor const& new_test)
        {
            m_tests.push_back(new_test);
        }

        void scope::operator () (void) const
        {
            return run();
        }

        void scope::run() const
        {
            std::cout << "Enter \"" << m_name << '"' << std::endl;
            std::for_each(m_tests.begin(), m_tests.end(),
                [](test_functor const& single_test)
                {
                    try
                    {
                        single_test();
                    }
                    catch (std::exception& e)
                    {
                        std::cout << "Exception: " << e.what() << std::endl;
                    }
                }
            );
            std::cout << "Exit \"" << m_name << '"' << std::endl;
        }

        application::application()
            : test::scope("Test application", false)
        {
        }

        application& application::instance()
        {
            static std::unique_ptr<application> instance;
            if (!instance)
            {
                instance.reset(new application);
            }
            return *instance;
        }

        void application::failed(std::string const& message)
        {
            instance().m_fails += "\n" + message;
        }

        void check::info(std::string const& message, char const* file, int line, char const* function)
        {
            std::string file_name(file);
            {
                auto pos = file_name.find_last_of("\\/");
                if (pos != std::string::npos)
                    file_name.erase(0, pos + 1);
            }
            std::string function_name(function);
            {
                auto pos = function_name.rfind("::");
                if (pos != std::string::npos)
                    function_name.erase(pos);
            }
            std::cout << file_name << '(' << line << ") [" << function_name << "] CHECK\n > " << message;
        }

        bool check::failed(std::string const& message, char const* file, int line, char const* function)
        {
            check::info(message, file, line, function);
            std::cout << " - FAILED!" << std::endl;
            return false;
        }

        bool check::succeed(std::string const& message, char const* file, int line, char const* function)
        {
            //check::info(message, file, line, function);
            std::cout << message;
            std::cout << " - OK." << std::endl;
            return true;
        }
    }
}

// sine qua non
