#include <iostream>

namespace Library
    {
        int SetInput(const int aInputMin, const int aInputMax)
        {
            int inputInt{};
            const int inputMin = aInputMin;
            const int inputMax = aInputMax;
            while (true)
            {
                std::cout << "Choice: " << std::endl;
                std::cin >> inputInt;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                else if (inputMin <= inputInt && inputInt <= inputMax)
                {
                    break;
                }
            }
            return inputInt;
        };

        void SayRoomMenu()
        {
            std::cout << "I am in the main menu saying the dungoeon name" << std::endl;
            std::cout << "These are the choices" << std::endl;
            std::cout << "1: Explore\t 2: Attack the Monsters!\t 3: See your stats\t 4: Open Door " << std::endl;
        }
    }
