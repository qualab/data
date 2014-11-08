/// @author Владимир Керимов

#pragma once

#include <sstream>
#include <deque>

#define DATA_CHECK_IS_TRUE(statement) \
    data::test::check::is_true(statement, #statement ## " is true", __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_IS_FALSE(statement) \
    data::test::check::is_false(statement, #statement ## " is false", __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_EQUAL(left, right) \
    data::test::check::equal(left, right, #left ## " == " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_EQUAL(left, right) \
    data::test::check::not_equal(left, right, #left ## " != " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_GREATER(left, right) \
    data::test::check::greater(left, right, #left ## " > " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_GREATER(left, right) \
    data::test::check::not_greater(left, right, #left ## " <= " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_LESS(left, right) \
    data::test::check::less(left, right, #left ## " < " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_LESS(left, right) \
    data::test::check::not_less(left, right, #left ## " >= " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_CLOSE(left, right, epsilon) \
    data::test::check::close(left, right, epsilon, "| " ## #left ## " - " ## #right ## " | < " ## #epsilon, \
                             __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_CLOSE(left, right, epsilon) \
    data::test::check::not_close(left, right, epsilon, "| " ## #left ## " - " ## #right ## " | >= " ## #epsilon, \
                                 __FILE__, __LINE__, __FUNCTION__)

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
            static scope& instance();
        };

        class check
        {
        public:
            static void info(std::string const& message, char const* file, int line, char const* function);
            static bool failed(std::string const& message, char const* file, int line, char const* function);
            static bool succeed(std::string const& message, char const* file, int line, char const* function);

            template <typename statement_type>
            static bool is_true(statement_type const& statement,
                char const* message, char const* file, int line, char const* function)
            {
                if (statement)
                    return check::succeed(message, file, line, function);
                else
                    return check::failed(message, file, line, function);
            }

            template <typename statement_type>
            static bool is_false(statement_type const& statement,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(!statement, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static bool equal(left_type left, right_type right,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left == right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static void not_equal(left_type const& left,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left != right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static bool greater(left_type left, right_type right,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left > right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static void not_greater(left_type const& left,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left <= right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static bool less(left_type left, right_type right,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left < right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static bool not_less(left_type const& left,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left >= right, message, file, line, function);
            }

            template <typename left_type, typename right_type, typename epsilon_type>
            static bool close(left_type left, right_type right, epsilon_type epsilon,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(std::abs(left - right) < epsilon, message, file, line, function);
            }

            template <typename left_type, typename right_type, typename epsilon_type>
            static bool not_close(left_type left, right_type right, epsilon_type epsilon,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(std::abs(left - right) >= epsilon, message, file, line, function);
            }
        };
    }
}

// sine qua non
