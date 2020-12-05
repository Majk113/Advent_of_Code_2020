#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <functional>
#include <sstream>
#include <memory>


std::vector<std::string> requiredField = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };
std::string optionalField = "cid";

struct Passport
{
    using fun_ptr = bool (Passport::*)(std::string);
    std::map<std::string, fun_ptr> validatorsMap;
    bool result;
    
    bool checkByr(std::string input);
    bool checkIyr(std::string input);
    bool checkEyr(std::string input);
    bool checkHgt(std::string input);
    bool checkHcl(std::string input);
    bool checkEcl(std::string input);
    bool checkPid(std::string input);
    bool checkCid(std::string input);
    bool getValidity();

    Passport();
    Passport(std::string pass)
    {
        std::string parameter;
        result = true;

        validatorsMap["byr"] = &Passport::checkByr;
        validatorsMap["iyr"] = &Passport::checkIyr;
        validatorsMap["eyr"] = &Passport::checkEyr;
        validatorsMap["hgt"] = &Passport::checkHgt;
        validatorsMap["hcl"] = &Passport::checkHcl;
        validatorsMap["ecl"] = &Passport::checkEcl;
        validatorsMap["pid"] = &Passport::checkPid;
        validatorsMap["cid"] = &Passport::checkCid;

        std::stringstream ss(pass);
        ss >> parameter;
        while (!ss.eof())
        {
            fun_ptr f = validatorsMap[parameter.substr(0, parameter.find(':'))];
            result &= (this->*f)(parameter.substr(parameter.find(':')+1, parameter.size() - 1));
            ss >> parameter;
        } 
    }
};

bool Passport::getValidity()
{
    return result;
}

bool Passport::checkByr(std::string input)
{
    if (input.size() < 4)
        return false;

    int bithYear = std::stoi(input);

    if ((bithYear >= 1920) && (bithYear <= 2002))
        return true;
    else
        return false;
}

bool Passport::checkIyr(std::string input)
{
    if (input.size() < 4)
        return false;

    int issueYear = std::stoi(input);

    if ((issueYear >= 2010) && (issueYear <= 2020))
        return true;
    else
        return false;
}

bool Passport::checkEyr(std::string input)
{
    if (input.size() < 4)
        return false;

    int expirationYear = std::stoi(input);

    if ((expirationYear >= 2010) && (expirationYear <= 2030))
        return true;
    else
        return false;
}

bool Passport::checkHgt(std::string input)
{
    int height = 0;
    int unitPosition;
    
    if (!(input.find("cm") ^ input.find("in")))
        return false;

    unitPosition = input.find("cm");
    if (unitPosition >= 0)
    {
        height = std::stoi(input.substr(0, (input.find("cm"))));
        if ((height >= 150) && (height <= 193))
            return true;
        else
            return false;
    }
    else
    {
        height = std::stoi(input.substr(0, (input.find("in"))));
        if ((height >= 59) && (height <= 76))
            return true;
        else
            return false;
    }

}

bool Passport::checkHcl(std::string input)
{
    if (input.size() != 7)
        return false;
    
    if (input[0] != '#')
        return false;

    try
    {
        std::string debug = input.substr(1, 6);
        return true;
    }
    catch (...)
    {
        return false;
    }
}
bool Passport::checkEcl(std::string input)
{
    std::vector<std::string> allowedColors = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };
    if (std::find(allowedColors.begin(), allowedColors.end(), input) == allowedColors.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Passport::checkPid(std::string input)
{
    if (input.size() != 9)
    {
        return false;
    }

    try
    {
        stoi(input);
        return true;
    }
    catch (...)
    {
        return false;
    }
}   

bool Passport::checkCid(std::string input)
{
    return true;
}

bool validate(std::string input)
{
    bool result = true;

    for (std::string field : requiredField)
    {
        if (input.find(field) == -1)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    std::fstream inputData;
    std::vector<std::string> listOfPassports(1000);
    std::vector<Passport> dataVerification;
    std::string line;
    int passportIndex = 0;
    int validCounter = 0;
    int validCounter2 = 0;
    bool validationResult;
    std::stringstream ss("asdasd rtyrty");

    inputData.open("day4input.txt");
    for (int i = 0; i < 1138; ++i)
    {
        std::getline(inputData, line);
        if (line.empty())
        {
            passportIndex+=1;
        }
        else
        {
            listOfPassports[passportIndex] += line;
            listOfPassports[passportIndex] += " ";
        }
    }
    inputData.close();

    for (std::string passport : listOfPassports)
    {
        if (passport.empty())
            break;

        validationResult = validate(passport);
        if (validationResult)
        {
            validCounter++;
            dataVerification.push_back(Passport(passport));
        }
    }
    std::cout << validCounter << std::endl;

    for (Passport pass : dataVerification)
    {
        validCounter2 += static_cast<int>(pass.getValidity());
    }
    std::cout << validCounter2 << std::endl;
}
