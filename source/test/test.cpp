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
            get_instance().m_tests.push_back(new_test);
        }

        void scope::run()
        {
            std::cout << "Test scope started." << std::endl;
            std::for_each(get_instance().m_tests.begin(), get_instance().m_tests.end(),
                [](test* single_test) {
                single_test->run();
            }
            );
            std::cout << "Test scope finished." << std::endl;
        }

        scope::scope()
        {
        }

        scope& scope::get_instance()
        {
            static std::unique_ptr<scope> instance;
            if (!instance)
            {
                instance.reset(new scope);
            }
            return *instance;
        }

        void check::info(std::string const& message, char const* file, int line)
        {
            std::string file_name(file);
            auto pos = file_name.find_last_of("\\/");
            if (pos != std::string::npos)
                file_name.erase(0, pos + 1);
            std::cout << file_name << '(' << line << ") CHECK: " << message;
        }

        void check::failed(std::string const& message, char const* file, int line)
        {
            check::info(message, file, line);
            std::cout << " - FAILED!" << std::endl;
        }

        void check::succeed(std::string const& message, char const* file, int line)
        {
            check::info(message, file, line);
            std::cout << " - OK." << std::endl;
        }
    }
}

// sine qua non
