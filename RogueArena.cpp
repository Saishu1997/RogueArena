#include "Arena.h"
#include <iostream>
#include <limits>

int main()
{
    std::cout << "MAIN START\n";

    Arena arena;
    arena.Run();
    std::cout << "Arena::Run() CALLED\n";


    std::cout << "\nPress ENTER to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}

