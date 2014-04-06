#include "test.hpp"
#include <iostream>
#include <cstdlib>
#include <conio.h>

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
    data::test::scope::run();
    return 0;
}
