#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Instruction
{
    std::string instruction;
    int argument;
    bool wasUsed = false;
    Instruction();
    Instruction(std::string line);
};


Instruction::Instruction(std::string line)
{
    size_t signPosition = line.find('+');

    if (signPosition == std::string::npos)
    {
        signPosition = line.find('-');
    }

    instruction = line.substr(0, signPosition-1);

    if (line[signPosition] == '+')
    {
        argument = stoi(line.substr(signPosition, line.size() - 1));
    }
    else if (line[signPosition] == '-')
    {
        argument = (stoi(line.substr(signPosition, line.size() - 1)));
    }
    else
    {
        std::cout << "cos jest bardzo nie tak\n";
    }
}

int main()
{
    std::string inputBuffer;
    std::vector<Instruction> program;
    int i;
    long accumulator;

    for (i = 0; i < 1000; ++i)
    {
        std::getline(std::cin, inputBuffer);
        if (inputBuffer == "")
            break;

        program.push_back(Instruction(inputBuffer));
    }

    for (int i = 0; i < program.size(); ++i)
    {
        for (int j = 0; j < program.size(); ++j)
        {
            program[j].wasUsed = false;
        }

        accumulator = 0;
        if (program[i].instruction == "jmp")
        {
            program[i].instruction = "nop";
        }
        else if (program[i].instruction == "nop")
        {
            program[i].instruction = "jmp";
        }
        else
        {
            continue;
        }

        for (auto pointer = program.begin();;)
        {
            if (pointer >= program.end())
            {
                std::cout << "Program terminated corectly: " << accumulator << std::endl;
                break;
            }

            if (pointer->wasUsed == true)
            {
                std::cout << "Infinite loop:" << accumulator << std::endl;
                break;
            }
            else
            {
                pointer->wasUsed = true;
                if (pointer->instruction == "acc")
                {
                    accumulator += (*pointer).argument;
                    ++pointer;
                }
                else if (pointer->instruction == "jmp")
                {
                    pointer += pointer->argument;
                }
                else if (pointer->instruction == "nop")
                {
                    ++pointer;
                }
            }
        }
        

        if (program[i].instruction == "jmp")
        {
            program[i].instruction = "nop";
        }
        else if (program[i].instruction == "nop")
        {
            program[i].instruction = "jmp";
        }
    }
        

    std::cout << "Hello World!\n";
}
