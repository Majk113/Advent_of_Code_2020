#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

int solution(std::string input)
{
    int min = 0;
    int max = 127;
    int i;
    int row = 0;
    int column = 0;
    for (i = 0; i < 7; ++i)
    {
        if (input[i] == 'B')
        {
            min += pow(2, 6 - i);
        }
        else if (input[i] == 'F')
        {
            max -= pow(2, 6 - i);
        }
    }
    row = min;
    min = 0;
    max = 7;

    for (; i < 10; ++i)
    {
        if (input[i] == 'R')
        {
            min += pow(2, 9 - i);
        }
        else if (input[i] == 'F')
        {
            max -= pow(2, 9 - i);
        }
    }
    return ((8 * row) + min);
}

int main()
{  
    std::vector<int> listOfSeats;
    int highest = 0;
    int seatId;
    
    for (int i = 0; i < 798; ++i)
    {
        std::string seat;
        std::cin >> seat;
        seatId = solution(seat);
        listOfSeats.push_back(seatId);
        highest = highest > seatId ? highest : seatId;
    }
    std::sort(listOfSeats.begin(), listOfSeats.end());

    for (int i = 0; i < listOfSeats.size()-1; ++i)
    {
        if ((listOfSeats[i + 1] - listOfSeats[i]) > 1)
        {
            std::cout << (listOfSeats[i] + 1) << std::endl;
        }
    }

    std::cout << highest << std::endl;
}
