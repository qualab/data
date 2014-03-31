#include "test.hpp"

namespace data
{
    namespace test
    {
        std::deque<std::function<void()>> application::m_functions;
    }
}

int main()
{
    data::test::application::run();
    return 0;
}
