#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string expression = "plaid tan bags contain 3 vibrant teal bags, 4 mirrored gold bags.";
    std::regex re("(\w+ \w+) bags");
    std::smatch base_match;
    std::regex_match(expression, base_match, re);

    std::cout << "Hello World!\n";
}

