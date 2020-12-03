#include <iostream>
#include <string>
#include <vector>

unsigned long solution1(std::vector<std::string> input, int right, int down)
{
    int treeCounter = 0;
    int column = 0;


    for (int row =0; row <input.size(); row +=down)
    {
        if (input[row][column] == '#')
        {
            treeCounter++;
        }
        
        column += right;
        if (column >= input[row].size())
        {
            column = column - input[row].size();
        }
    }
    return treeCounter;
}

int main()
{
    std::vector<std::string> pattern;
    std::string singleLine;

    while (std::getline(std::cin, singleLine))
    {
        if (singleLine.empty())
            break;
        pattern.push_back(singleLine);
    }

    unsigned long result = solution1(pattern, 1, 1) * solution1(pattern, 3, 1) * solution1(pattern, 5, 1) * solution1(pattern, 7, 1) * solution1(pattern, 1, 2);
    std::cout << result << std::endl;
}