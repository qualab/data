#pragma once

#include <functional>
#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>

namespace data
{
    namespace test
    {
        class check
        {
        public:
            static void info(std::string const& message, char const* file, int line)
            {
                std::cout << "FILE: " << file << '(' << line << ") CHECK: " << message;
            }

            static void failed(std::string const& message, char const* file, int line)
            {
                check::info(message, file, line);
                std::cout << " - FAILED!" << std::endl;
            }

            static void succeed(std::string const& message, char const* file, int line)
            {
                check::info(message, file, line);
                std::cout << " - OK." << std::endl;
            }

            template <typename left_type, typename right_type>
            static void equal(left_type left, right_type right, char const* file, int line)
            {
                std::stringstream stream;
                stream << left << " == " << right;
                if (left != right)
                {
                    check::failed(stream.str(), file, line);
                }
                else
                {
                    check::succeed(stream.str(), file, line);
                }
            }
        };

        class application
        {
        public:
            static void add_test(std::function<void()> const& test_function)
            {
                m_functions.push_back(test_function);
            }

            static void run()
            {
                std::cout << "Test application started." << std::endl;
                std::for_each(m_functions.begin(), m_functions.end(),
                    [](std::function<void()> const& test_function) {
                        test_function();
                    }
                );
                std::cout << "Test application finished." << std::endl;
            }

        private:
            static std::deque<std::function<void()>> m_functions;
        };
    }
}
