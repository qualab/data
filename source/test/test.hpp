/// @author Владимир Керимов

#pragma once

#include <functional>
#include <string>
#include <deque>

#define DATA_CHECK_IS_TRUE(statement) \
    data::test::check::is_true((statement), #statement ## " is true", __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_IS_FALSE(statement) \
    data::test::check::is_false((statement), #statement ## " is false", __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_EQUAL(left, right) \
    data::test::check::equal((left), (right), #left ## " == " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_EQUAL(left, right) \
    data::test::check::not_equal((left), (right), #left ## " != " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_GREATER(left, right) \
    data::test::check::greater((left), (right), #left ## " > " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_GREATER(left, right) \
    data::test::check::not_greater((left), (right), #left ## " <= " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_LESS(left, right) \
    data::test::check::less((left), (right), #left ## " < " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_LESS(left, right) \
    data::test::check::not_less((left), (right), #left ## " >= " ## #right, __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_CLOSE(left, right, epsilon) \
    data::test::check::close((left), (right), (epsilon), "| " ## #left ## " - " ## #right ## " | < " ## #epsilon, \
                             __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NOT_CLOSE(left, right, epsilon) \
    data::test::check::not_close((left), (right), (epsilon), "| " ## #left ## " - " ## #right ## " | >= " ## #epsilon, \
                                 __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_EXCEPTION_THROWN(exception_type, statement) \
    data::test::check::exception_thrown<exception_type>([&]() { statement; }, \
                                        #exception_type ## " thrown from " ## #statement, \
                                        __FILE__, __LINE__, __FUNCTION__)
#define DATA_CHECK_NO_EXCEPTION_THROW(statement) \
    data::test::check::no_exception_thrown([&]() { statement; }, "No exception throw from " ## #statement, \
                                           __FILE__, __LINE__, __FUNCTION__)

namespace data
{
    namespace test
    {
        typedef std::function<void()> test_functor;

        class scope
        {
        public:
            void add_test(test_functor const& new_test);

            void operator () (void) const;
            void run() const;

        protected:
            scope(std::string const& name, bool add_to_application = true);

        private:
            std::deque<test_functor> m_tests;
            std::string m_name;
        };

        class application : public test::scope
        {
        public:
            static application& instance();

            void failed(std::string const& message);

        private:
            std::string m_fails;

            application();
            application(application const&);
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
            static bool equal(left_type const& left, right_type const& right,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left == right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static void not_equal(left_type const& left, right_type const& right,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(left != right, message, file, line, function);
            }

            template <typename left_type, typename right_type>
            static bool greater(left_type const&, right_type const& right,
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
            static bool less(left_type const& left, right_type const& right,
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
            static bool close(left_type const& left, right_type const& right, epsilon_type epsilon,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(std::abs(left - right) < epsilon, message, file, line, function);
            }

            template <typename left_type, typename right_type, typename epsilon_type>
            static bool not_close(left_type const& left, right_type const& right, epsilon_type epsilon,
                char const* message, char const* file, int line, char const* function)
            {
                return check::is_true(std::abs(left - right) >= epsilon, message, file, line, function);
            }

            template <typename exception_type, typename functor_type>
            static bool exception_thrown(functor_type const& functor,
                char const* message, char const* file, int line, char const* function)
            {
                try
                {
                    functor();
                }
                catch (exception_type&)
                {
                    return check::succeed(message, file, line, function);
                }
                catch (...)
                {
                    return check::failed(std::string(message) + " unexpected exception thrown!", file, line, function);
                }
                return check::failed(std::string(message) + " no exception thrown!", file, line, function);
            }
            
            template <typename functor_type>
            static bool no_exception_thrown(functor_type const& functor,
                char const* message, char const* file, int line, char const* function)
            {
                try
                {
                    functor();
                }
                catch (...)
                {
                    return check::failed(message, file, line, function);
                }
                return check::succeed(message, file, line, function);
            }
        };
    }
}

// sine qua non
