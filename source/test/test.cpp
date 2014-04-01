#include "test.hpp"
#include <iostream>
#include <cstdlib>
#include <conio.h>

namespace data
{
    namespace test
    {
        std::deque<std::function<void()>> application::m_functions;

        void test_object();
    }
}

namespace
{
    void press_any_key()
    {
        std::cout << "\nPress any key... ";
        _getch();
    }
}

int main()
{
    std::atexit(press_any_key);
    data::test::test_object();
    data::test::application::run();
    return 0;
}
