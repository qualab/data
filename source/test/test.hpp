/// @author Владимир Керимов

#pragma once

#include <sstream>
#include <deque>

namespace data
{
    namespace test
    {
        class test
        {
        public:
            test();
            virtual void run() = 0;
        };

        class scope
        {
        public:
            static void add_test(test* new_test);
            static void run();

        private:
            std::deque<test*> m_tests;

            scope();
            static scope& get_instance();
        };

        class check
        {
        public:
            static void info(std::string const& message, char const* file, int line);
            static void failed(std::string const& message, char const* file, int line);
            static void succeed(std::string const& message, char const* file, int line);

            template <typename left_type, typename right_type>
            static void equal(left_type left, right_type right, char const* file, int line)
            {
                std::stringstream stream;
                stream << left << " == " << right;
                if (left == right)
                {
                    check::succeed(stream.str(), file, line);
                }
                else
                {
                    check::failed(stream.str(), file, line);
                }
            }

            template <typename left_type, typename right_type, typename epsilon_type>
            static void almost(left_type left, right_type right, epsilon_type epsilon, char const* file, int line)
            {
                std::stringstream stream;
                stream << "| " << left << " - " << right << " | < " << epsilon;
                if (std::abs(left - right) < epsilon)
                {
                    check::succeed(stream.str(), file, line);
                }
                else
                {
                    check::failed(stream.str(), file, line);
                }
            }
        };
    }
}

// sine qua non
