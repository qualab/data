/// @author Владимир Керимов

#include "test.hpp"
#include <data/object>
#include <data/exception>

namespace data
{
    namespace test
    {
        class test_object : public test
        {
        public:
            virtual void run() override
            {
                data::object empty;
                DATA_CHECK_IS_TRUE(empty.is_null());
                DATA_CHECK_EXCEPTION_THROWN(null_representation_error, empty.as<int>());

                data::object obj = data::object(123);
                DATA_CHECK_EQUAL(obj.as<int>(), 123);
                DATA_CHECK_EQUAL(obj.as<int64_t>(), 123);
                DATA_CHECK_EQUAL(obj.as<double>(), 123);
                DATA_CHECK_EQUAL(obj.as<uint8_t>(), 123);

                data::object real = data::object(3.14159);
                DATA_CHECK_CLOSE(real.as<double>(), 3.14159, 1e-15);
            }
        } g_test_object;
    }
}

// sine qua non
