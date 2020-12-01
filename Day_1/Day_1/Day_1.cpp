#include <iostream>

int solution(int input[])
{
    int sizeOfArray = 200;

    for (int i = 0; i < sizeOfArray; ++i)
    {
        for (int j = 0; j < sizeOfArray; ++j)
        {
            if (i == j)
                continue;
            else if ((input[i] + input[j]) == 2020)
                return (input[i] * input[j]);
        }
    }
}

int solution2(int input[])
{
    int sizeOfArray = 200;

    for (int i = 0; i < sizeOfArray; ++i)
    {
        for (int j = 0; j < sizeOfArray; ++j)
        {
            for (int k = 0; k < sizeOfArray; ++k)
            {
                if ((k == i) || (k == j) || (j == i))
                    continue;
                else if ((input[k] + input[j] + input[i]) == 2020)
                    return (input[k] * input[j] * input[i]);
            }
        }
    }
    return 0;
}

int main()
{
    int a[200];
    
    for (int k = 0; k < 200; ++k)
    {
        std::cin >> a[k];
    }

    std::cout << solution(a) << std::endl;
    std::cout << solution2(a) << std::endl;
}