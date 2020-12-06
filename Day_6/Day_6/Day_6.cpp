#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct Group
{
	std::unordered_set<char> allYeses;
	std::string allAnswers;
	int peopleCounter;
	int getOnlyFullYeses();
};

int Group::getOnlyFullYeses()
{
	int result = 0;
	for (char c : allYeses)
	{
		if (std::count(allAnswers.begin(), allAnswers.end(), c) == peopleCounter)
			result++;
	}
	return result;
}

int main()
{
	std::vector<std::unordered_set<char>> listOfAnswers(1000);
	std::vector<Group> listOfGroups(1000);
	int index = 0;

	for (int i = 0; i < 2179; ++i)
	{
		std::string line;
		std::getline(std::cin, line);

		if (line.empty())
		{
			index++;
		}
		else
		{
			for (char c : line)
			{
				listOfGroups[index].allYeses.insert(c);
				listOfGroups[index].allAnswers += line;
				listOfGroups[index].peopleCounter++;
			}
		}
	}

	int first_answer = 0;
	int second_answer = 0;

	for_each(listOfGroups.begin(), listOfGroups.end(), [&](Group g)
		{
			first_answer += g.allYeses.size();
			second_answer += g.getOnlyFullYeses();
		});


	std::cout << "Hello worold\n";
	std::cout << first_answer << std::endl;
	std::cout << second_answer << std::endl;
}
