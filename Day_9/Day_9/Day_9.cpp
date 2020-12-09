#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


bool findTwoNumbersToSum(std::vector<unsigned long long int>::iterator beginRange, 
                         std::vector<unsigned long long int>::iterator stopRange, 
                         unsigned long long sum)
{
    for (auto i = beginRange; i <= stopRange; ++i)
    {
        for (auto j = i + 1; j <= stopRange; ++j)
        {
            if ((*i + *j) == sum)
                return true;
        }
    }
    return false;
}


int main()
{
    std::vector<unsigned long long int> input;
    unsigned long long int largeNumber;

    for (int i=0; i<1000; ++i )
    {
        std::cin >> largeNumber;
        input.push_back(largeNumber);
    }
    std::cout << std::endl;

    auto preambleStart = input.begin();
    auto preambleStop = input.begin() + 24;

    for (auto number = input.begin() + 25; number < input.end(); ++number, ++preambleStart, ++preambleStop)
    {
        if (!findTwoNumbersToSum(preambleStart, preambleStop, *number))
        {
            std::cout << *number;
            break;
        }
    }
}