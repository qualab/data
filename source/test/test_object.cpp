/// @author Владимир Керимов

#include "test.hpp"
#include <data/object>
#include <data/exception>

namespace data
{
    namespace test
    {
        class test_object : public test::scope
        {
        public:
            static void test_empty()
            {
                data::object empty;
                DATA_CHECK_IS_TRUE(empty.is_null());
                DATA_CHECK_EXCEPTION_THROWN(null_representation_error, empty.as<int>());
                DATA_CHECK_EXCEPTION_THROWN(null_representation_error, empty.as<float>());
                DATA_CHECK_IS_FALSE(empty.as<bool>());
            }

            static void test_integer()
            {
                data::object integer = data::object(123);
                DATA_CHECK_EQUAL(integer.as<int>(), 123);
                DATA_CHECK_EQUAL(integer.as<int64_t>(), 123);
                DATA_CHECK_EQUAL(integer.as<double>(), 123);
                DATA_CHECK_EQUAL(integer.as<uint8_t>(), 123);
                DATA_CHECK_IS_TRUE(integer.as<bool>());
            }

            static void test_real()
            {
                data::object real = data::object(3.14159);
                DATA_CHECK_CLOSE(real.as<double>(), 3.14159, 1e-15);
                DATA_CHECK_EQUAL(real.as<int>(), 3);
                DATA_CHECK_IS_TRUE(real.as<bool>());
                DATA_CHECK_IS_FALSE(true);
            }

            test_object()
                : test::scope("Test data::object")
            {
                add_test(test_empty);
                add_test(test_integer);
                add_test(test_real);
            }

        } g_test_object;
    }
}

// sine qua non
