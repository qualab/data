/// @author Владимир Керимов

#include "test.hpp"
#include <data/cast>

namespace data
{
    namespace test
    {
        class test_cast : public test
        {
        public:
            virtual void run() override
            {
                DATA_CHECK_EXCEPTION_THROWN(nonexistent_type_cast, cast<unsigned>(-1));
                DATA_CHECK_EQUAL(cast<int>(100500uLL), 100500);
                DATA_CHECK_EQUAL(cast<long long>(-123), -123LL);
            }
        } g_test_object;
    }
}

// sine qua non
