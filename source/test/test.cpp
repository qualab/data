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
    std::atexit(press_any_key);
    data::test::scope::run();
    return 0;
}

namespace data
{
    namespace test
    {
        test::test()
        {
            scope::add_test(this);
        }

        void scope::add_test(test* new_test)
        {
            instance().m_tests.push_back(new_test);
        }

        void scope::run()
        {
            std::cout << "Test scope started." << std::endl;
            std::for_each(instance().m_tests.begin(), instance().m_tests.end(),
                [](test* single_test)
                {
                    try
                    {
                        single_test->run();
                    }
                    catch (std::exception& e)
                    {
                        std::cout << "Exception: " << e.what() << std::endl;
                    }
                }
            );
            std::cout << "Test scope finished." << std::endl;
        }

        scope::scope()
        {
        }

        scope& scope::instance()
        {
            static std::unique_ptr<scope> instance;
            if (!instance)
            {
                instance.reset(new scope);
            }
            return *instance;
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
            check::info(message, file, line, function);
            std::cout << " - OK." << std::endl;
            return true;
        }
    }
}

// sine qua non
