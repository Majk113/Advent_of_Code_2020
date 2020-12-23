#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


bool findTwoNumbersToSum(std::vector<unsigned long long int>::iterator beginRange, 
                         std::vector<unsigned long long int>::iterator stopRange, 
                         unsigned long long int sum)
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

std::vector<unsigned long long int>::iterator findConiguousSum(std::vector<unsigned long long int>::iterator beginRange, 
                                                               unsigned long long int sum)
{
    unsigned long long int currentSum = *beginRange;
    std::vector<unsigned long long int>::iterator savedFirstPosition = beginRange;

    while (currentSum < sum)
    {
        ++beginRange;
        currentSum += *beginRange;
    } 

    if (currentSum == sum)
    {
        return beginRange;
    }
    else
    {
        return savedFirstPosition;
    }

}


int main()
{
    std::vector<unsigned long long int> input;
    unsigned long long int largeNumber;
    unsigned long long int sumToFind = 0;
    unsigned long long int endOfDivision;

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
            sumToFind = 507622668;
            std::cout << sumToFind << "\n";
            break;
        }
    }

    for (auto divisionStart = input.begin(); divisionStart < input.end(); ++divisionStart)
    {
        auto endOfDivisionPointer = findConiguousSum(divisionStart, sumToFind);
        
        if (endOfDivisionPointer != divisionStart)
        {
            auto minMax = std::minmax_element(divisionStart, endOfDivisionPointer);
            unsigned long long int result = *(minMax.first) + *(minMax.second);
            std::cout << result << "\n";
            break;
        }
    }
}   
