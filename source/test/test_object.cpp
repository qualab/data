#include "test.hpp"
#include <data/object>

namespace data
{
    namespace test
    {
        class test_object : public test
        {
        public:
            virtual void call() override
            {
                data::object obj = 123;
                check::equal(obj.get_as<int>(), 123, __FILE__, __LINE__);
            }
        } g_test_object;
    }
}
