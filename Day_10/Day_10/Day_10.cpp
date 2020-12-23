#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	std::vector<int> input;
	std::vector<int> difference(111);

	int oneDifferences = 0;
	int threeDifferences = 0;

	for (int i = 0; i < 110; ++i)
	{
		int adapter;
		std::cin >> adapter;
		input.push_back(adapter);
	}

	std::sort(input.begin(), input.end());
	std::adjacent_difference(input.begin(), input.end(), difference.begin());
	oneDifferences = std::count(difference.begin() + 1, difference.end(), 1) + 1;
	threeDifferences = std::count(difference.begin() + 1, difference.end(), 3) + 1;
	
	std::cout << "Hello world\n";
	std::cout << (oneDifferences * threeDifferences);
}

