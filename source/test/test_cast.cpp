﻿/// @author Владимир Керимов

#include "test.hpp"
#include <data/cast>

namespace data
{
    namespace test
    {
        class test_cast : public test::scope
        {
        public:
            static void test_misc()
            {
                DATA_CHECK_EXCEPTION_THROWN(nonexistent_type_cast, cast<unsigned>(-1));
                DATA_CHECK_EQUAL(cast<int>(100500uLL), 100500);
                DATA_CHECK_EQUAL(cast<long long>(-123), -123LL);
            }

            static void test_uint8()
            {
                DATA_CHECK_EXCEPTION_THROWN(nonexistent_type_cast, cast<uint8_t>(256uLL));
                DATA_CHECK_EQUAL(cast<uint8_t>(123), 123u);
                DATA_CHECK_EQUAL(cast<uint8_t>(255u), 255u);
                DATA_CHECK_EQUAL(cast<uint8_t>(0LL), 0);
                DATA_CHECK_EXCEPTION_THROWN(nonexistent_type_cast, cast<uint8_t>(-1));
            }

            static void test_int8()
            {
                DATA_CHECK_EXCEPTION_THROWN(nonexistent_type_cast, cast<int8_t>(128u));
                DATA_CHECK_EQUAL(cast<int8_t>(127uLL), 127);
                DATA_CHECK_EQUAL(cast<int8_t>(-1LL), -1);
                DATA_CHECK_EQUAL(cast<int8_t>(-128), -128);
                DATA_CHECK_EXCEPTION_THROWN(nonexistent_type_cast, cast<int8_t>(-129LL));
            }

            test_cast()
                : test::scope("Test data::cast")
            {
                add_test(test_misc);
                add_test(test_uint8);
                add_test(test_int8);
            }

        } g_test_object;
    }
}

// sine qua non
