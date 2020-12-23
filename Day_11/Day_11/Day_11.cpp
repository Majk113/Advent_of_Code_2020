#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> input;

void verifySeat(int x, int y)
{
    int occupiedSeatsCounter = 0;

    input[x - 1][y - 1];
    input[x][y - 1];
    input[x + 1][y - 1];

    input[x][y - 1];
    input[x][y + 1];

    input[x - 1][y + 1];
    input[x][y + 1];
    input[x + 1][y + 1];
}


int main()
{
    std::string line;

    for (int i = 0; i < 10; ++i)
    {
        std::cin >> line;

        
    }

    std::cout << "Hello World!\n";
}

