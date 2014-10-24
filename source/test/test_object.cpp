/// @author Владимир Керимов

#include "test.hpp"
#include <data/object>

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
                check::equal(empty.is_null(), true, __FILE__, __LINE__);

                data::object obj = data::object(123);
                check::equal(obj.as<int>(), 123, __FILE__, __LINE__);

                data::object real = data::object(3.14159);
                check::almost(real.as<double>(), 3.14159, 1e-15, __FILE__, __LINE__);
            }
        } g_test_object;
    }
}

// sine qua non
