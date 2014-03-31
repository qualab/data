#include "test.hpp"
#include <data/object>

namespace data
{
    namespace test
    {
        void test_integer()
        {
            data::object obj = 123;
            check::equal(obj.get_as<int>(), 123, __FILE__, __LINE__);
        }

        void test_object()
        {
            application::add_test(test_integer);
        }
    }
}
