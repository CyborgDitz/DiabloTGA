#include "GameManager.h"
#include <iostream>
#include <ostream>
#include "Library.h"

void GameManager::PrintEnemyStats(Enemy* aEnemyType)
{
    {
        std::cout << "SIX SEEVEEEEN" << aEnemyType << std::endl;
    }
}

void GameManager::PrintMainMenuChoices(Player& aPlayer)
{
    {
        std::cout << "Welcome to the Pits of Eternal Goob, " << aPlayer.GetName() << ' n'
            << "GGG_________OOO____OOO____BBB " << std::endl;
        {
            std::cout << "These are your choices" << std::endl;
            std::cout << "1: Enter Dungeon, 2: Cheats, 0: exit game" << std::endl;
        }
    }
}

void GameManager::PopulateRooms(std::vector<Room>& aRooms)
{
    aRooms.push_back(myRoom0);
    aRooms.push_back(myRoom1);
    aRooms.push_back(myRoom2);
    // std::cout<< "debug There are " << aRooms.size() << " rooms" << std::endl; 
}

void GameManager::PopulateDoors(std::vector<Door>& aDoors)
{
    aDoors.push_back(myDoor0);
    aDoors.push_back(myDoor1);
    aDoors.push_back(myDoor2);

    //std::cout<< "debug There are " << aDoors.size() << " doors" << std::endl; 
}

void GameManager::SetRoom()
{
    myCurrentRoom = &myCurrentDoor->GetNextRoom();
    myCurrentRoom = &myCurrentDoor->GetPrevRoom();
}

void GameManager::PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemyType, Room& aRoom)
{
    int enemiesAmount = aRoom.GetEnemiesAmount();
    for (int i = 0; i < enemiesAmount; i++)
    {
        aPopulation.push_back(aEnemyType);
    }
}

void GameManager::SetMainState()
{
    int min = static_cast<int>(MainState::Exit);
    int choice = Library::SetInput(min, sizeof(myMainState));
    myMainState = static_cast<MainState>(choice);
}

void GameManager::GameCombat()
{
    while (myPlayer.GetIsAlive() && myPopulation.empty() == false)
    {
        for (int i = 0; i < myPopulation.size(); i++)
        {
            std::cout << " Enemy target:" << i + 1 << std::endl;
            myPopulation[i].PrintStats();
        }
        std::cout << "pick a target " << std::endl;
        const int target = Library::SetInput(1, myPopulation.size()) - 1;
        int playerAtk = myPlayer.GetAtk();
        if (myPlayer.GetInfinite() == true)
        {
            playerAtk = 9999;
        }
        myPopulation[target].TakeDamage(playerAtk);

        if (myPopulation[target].GetIsAlive() == false)
        {
            myPopulation.erase(myPopulation.begin() + target);
        }
        for (int i = 0; i < myPopulation.size(); i++)
        {
            int mobAtk = myPopulation[i].GetAtk();
            if (myPlayer.GetGodMode() == true)
            {
                std::cout << "I am a god! " << mobAtk << std::endl;
                mobAtk = 0;
            }
            myPlayer.TakeDamage(mobAtk);
        }
    }
}

void GameManager::ChooseDoor()
{
    const int minInput = 1;
    const int doorAmount = (myDoors.size() - 1);
    while (true)
    {
        std::cout << "Pick a door! 1:next Room, 2: previous door" << std::endl;
        const int input = Library::SetInput(minInput, doorAmount);
        Door* theDoor = &myDoors[input];
        std::cout << "I am going into door " << input << " as the next door" << std::endl;

        if (theDoor->GetIsLocked() == true)
        {
            // std::cout << "entering next by default" << myCurrentDoor->GetNextRoom().GetName() << std::endl;
            theDoor->UnlockDoor(myPlayer);
            if (theDoor->GetIsLocked() == true)
            {
                return;
            }
        }
        else
        {
            std::cout << "Door is not locked!" << std::endl;
        }

        std::cout << "I am going into door " << input << " and I came from room: " << myCurrentRoom->GetName() <<
            std::endl;
        myCurrentDoor = &myDoors[input];

        if (input == 1)
        {
            myCurrentRoom = &myCurrentDoor->GetNextRoom();
            // std::cout << "I came from room: " << theDoor->GetPrevRoom().GetName() << std::endl;
            // std::cout << "I am going into room: " << theDoor->GetNextRoom().GetName() << std::endl;
        }
        else if (input == doorAmount)
        {
            myCurrentRoom = &myCurrentDoor->GetPrevRoom();
            // std::cout << "I came from room: " << theDoor->GetPrevRoom().GetName() << std::endl;
            // std::cout << "I am going into room: " << theDoor->GetNextRoom().GetName() << std::endl;
        }
        return;
    }
}

void GameManager::PopulateRoom()
{
    {
        if (myCurrentRoom->GetName() == myRooms[0].GetName())
        {
            PopulateEnemies(myPopulation, myEnemy0, myRooms[0]);
        }
        else if (myCurrentRoom->GetName() == myRoom1.GetName())
        {
            PopulateEnemies(myPopulation, myEnemy1, myRoom1);
        }
        else if (myCurrentRoom->GetName() == myRoom2.GetName())
        {
            PopulateEnemies(myPopulation, myEnemy2, myRoom2);
        }
    }
}

void GameManager::SetCheatState(Player& aPlayer)
{
    while (myCheatState != CheatState::Exit)
    {
        std::cout << "Select your cheat to toggle: \t1: Immortality \t2: Infinite Damage\n 3:"
            << "3: Both infinite and immortality \t0: Exit cheats with your choices" << std::endl;
        const int min = static_cast<int>(CheatState::Exit);
        const int max = static_cast<int>(CheatState::Count);
        const CheatState input = static_cast<CheatState>(Library::SetInput(min, max)); // get a setter
        switch (input)
        {
        case CheatState::Exit :
            {
                std::cout << "You are exiting the Cheat Menu with these cheats here" << std::endl;
                std::cout << "Your cheats are: " << std::endl;
                myCheatState = CheatState::Exit;
                myMainState = MainState::Menu;
                break;
            }
        case CheatState::GodMode :
            {
                if (aPlayer.GetInfinite() == true)
                {
                    aPlayer.SetInfinite(false);
                    std::cout << "You turned off infinite damage" << std::endl;
                }

                else
                {
                    aPlayer.SetGodMode(true);
                    std::cout << "You have GodMode and cant be harmed" << std::endl;
                }
                break;
            }
        case CheatState::InfiniteDPS :
            {
                if (aPlayer.GetGodMode() == true)
                {
                    aPlayer.SetInfinite(false);
                    std::cout << "You turned off infinite damage" << std::endl;
                }

                else
                {
                    aPlayer.SetInfinite(true);
                    std::cout << "You turned on infinite damage" << std::endl;
                }
                break;
            }
        case CheatState::BothCheats :
            {
                if (aPlayer.GetGodMode() == true && aPlayer.GetInfinite() == true)
                {
                    aPlayer.SetInfinite(false);
                    aPlayer.SetInfinite(false);
                    std::cout << "You have turned off infinite damage and godmode" << std::endl;
                }
                else
                {
                    aPlayer.SetGodMode(true);
                    aPlayer.SetInfinite(true);
                }
                std::cout << "You have have on infinite damage and godmode" << std::endl;
                break;
            }
        case CheatState::SayCheats :
            {
                if (aPlayer.GetGodMode() == true && aPlayer.GetInfinite() == true)
                {
                    std::cout << "You have infinite damage and god mode" << std::endl;
                }
                else if (aPlayer.GetGodMode() == true)
                {
                    std::cout << "You have godmode" << std::endl;
                }
                else if (aPlayer.GetInfinite() == true)
                {
                    std::cout << "You have infinite damage" << std::endl;
                }
                else
                {
                    std::cout << "You have no cheats" << std::endl;
                }
                break;
            }
        case CheatState::Count :
        default :
            {
                std::cout << "not that one" << std::endl;
                break;
            }
        }
    }
}

void GameManager::RoomMenuChoices()
{
    while (myRoomState != RoomState::Exit)
    {
        std::cout << "1: Open Door \t 2: Fight Monsters!\t 3:Explore Room\n" <<
            " 4: See yours and monsters stats\t 0: Exit the game" << std::endl;
        const int minInput = static_cast<int>(CheatState::Exit);
        const int maxInput = static_cast<int>(CheatState::Count);
        myRoomState = static_cast<RoomState>(Library::SetInput(minInput, maxInput));
        //call from room like print etc
        switch (myRoomState)
        {
        case RoomState::Exit :
            break;
        case RoomState::OpenDoor :
            {
                std::cout << "I am opening the doors" << std::endl;
                ChooseDoor();
                return;
            }
        case RoomState::Combat :
            {
                std::cout << "I am fighting" << std::endl;
                break;
            }
        case RoomState::Explore :
            {
                break;
            }
        case RoomState::PrintStats :
            {
                myPlayer.PrintStats();
                break;
            }
        case RoomState::Count :
        default :
            {
                break;
            }
        }
    }
}

bool GameManager::isEnemiesHere() const
{
    if (myPopulation.empty() == true)
    {
        std::cout << "you must fight!" << std::endl;
        return false;
    }
    else
    {
        std::cout << "There are no monsters to fight!" << std::endl;
        return true;
    }
}

void GameManager::RoomLoop()
{
    while (myPlayer.GetIsAlive() && myRoomState != RoomState::Exit)
    {
        myCurrentRoom = &myRooms[0];
        // std::cout << "Choose a room to test: 1, 2, 3" << std::endl;
        std::cout << "I am in room: " << myCurrentRoom->GetName() << std::endl;
        {
            myCurrentRoom->PrintRoomData();
            PopulateRoom();

            std::cout << "1: Open Door \t 2: Fight Monsters!\t 3:Explore Room\n" <<
                " 4: See yours and monsters stats\t 0: Exit the game" << std::endl;
            const int minInput = static_cast<int>(CheatState::Exit);
            const int maxInput = static_cast<int>(CheatState::Count);
            myRoomState = static_cast<RoomState>(Library::SetInput(minInput, maxInput));
            if (myPopulation.empty() == false)
            {
                std::cout << "you must fight!" << std::endl;
            }
            //call from room like print etc
            switch (myRoomState)
            {
            case RoomState::Exit :
                break;
            case RoomState::OpenDoor :
                {
                    if (myPopulation.empty() == false)
                    {
                        std::cout << "you must fight!" << std::endl;
                    }
                    else
                    {
                        std::cout << "I am opening the doors" << std::endl;
                        ChooseDoor();
                    }
                    break;
                }
            case RoomState::Combat :
                {
                    if (myPopulation.empty() == true)
                    {
                        std::cout << "There are no Enemies" << std::endl;
                    }
                    else
                    {
                        std::cout << "I am fighting" << std::endl;
                        GameCombat();
                    }
                    break;
                }
            case RoomState::Explore :
                {
                    myCurrentRoom->PrintRoomData();
                    break;
                }
            case RoomState::PrintStats :
                {
                    myPlayer.PrintStats();
                    break;
                }
            case RoomState::Count :
            default :
                {
                    break;
                }
            }
        }
    }
}

void GameManager::PlayGame()
{
    while (myMainState != MainState::Exit && myPlayer.GetIsAlive())
    {
        PrintMainMenuChoices(myPlayer); //TODO below func in mainmenu?
        SetGameState(static_cast<MainState>(Library::SetInput(0, sizeof(MainState))));

        switch (myMainState)
        {
        case MainState::Exit :
            {
                std::cout << "I am going out of game baii" << std::endl;
                break;
            }
        case MainState::Play :
            {
                std::cout << "I start in room " << myCurrentRoom->GetName() << std::endl;
                RoomLoop();
                break;
            }
        case MainState::Cheats :
            {
                std::cout << "You are in the  cheats menu\n" << std::endl;

                while (myMainState == MainState::Cheats)
                {
                    SetCheatState(myPlayer);
                }
                break;
            }
        case MainState::Menu :
            {
                break;
            }
        case MainState::Count :
            {
                break;
            }
        default : ;
        }
        {
            std::cout << "I am main menu choices again and want to maybe enter the dungeon" << std::endl;
        }
    }
}
