#include <iostream>
#include <string>
#include <algorithm>
#include <array>


struct Password
{
    int min;
    int max;
    char c;
    std::string pass;
};

int checkIfPasswordIsValid1(struct Password password)
{
    int counter = 0;
    for (char c : password.pass)
    {
        if (c == password.c)
            counter++;
    }

    if ((counter <= password.max) && (counter >= password.min))
        return 1;
    else
        return 0;
}

int checkIfPasswordIsValid2(struct Password password)
{
    if ((password.pass[password.min-1] == password.c) ^ (password.pass[password.max-1] == password.c))
        return 1;
    else
        return 0;
}

int main()
{
    std::array<Password, 1000> passwords;
    std::cout << "Hello World!\n";
    int validPasswords;

    for (int i = 0; i < 1000; ++i)
    {
        std::string ranges;
        std::cin >> ranges;

        std::string character;
        std::cin >> character;

        std::cin >> passwords[i].pass;

        size_t pos = ranges.find('-');

        passwords[i].min = stoi(ranges.substr(0, pos));
        passwords[i].max = stoi(ranges.substr(pos+1));
        passwords[i].c = character[0];
    }

    int counter = 0;
    int counter2 = 0;
    std::for_each(passwords.begin(), passwords.end(),
        [&](Password p)
        {
            counter += checkIfPasswordIsValid1(p);
        });

    std::for_each(passwords.begin(), passwords.end(),
        [&](Password p)
        {
            counter2 += checkIfPasswordIsValid2(p);
        });

    std::cout << counter << std::endl;
    std::cout << counter2 << std::endl;
}




