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
    std::cout<< "debug There are " << aRooms.size() << " rooms" << std::endl; 
}
void GameManager::PopulateDoors(std::vector<Door>& aDoors)
{
    aDoors.push_back(myDoor0);
    aDoors.push_back(myDoor1);
    aDoors.push_back(myDoor2);

    std::cout<< "debug There are " << aDoors.size() << " doors" << std::endl; 
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
    while (myPlayer.GetIsAlive() && !myPopulation.empty())
    {
        std::cout << "pick a target " << std::endl;
        for (int i = 0; i < myPopulation.size(); i++)
        {std::cout <<" Enemy target:" << i+1 << std::endl;
            myPopulation[i].PrintStats();
        }
       const int target = Library::SetInput(1, myPopulation.size())-1;
        myPopulation[target].TakeDamage(myPlayer.GetAtk());

        if (myPopulation[target].GetIsAlive() == false)
        {
            myPopulation.erase(myPopulation.begin() + target);
        }
        for (int i = 0; i < myPopulation.size(); i++)
        {
            myPlayer.TakeDamage(myPopulation[i].GetAtk());
        }
        // myPlayer.TakeDamage(enemy.GetAtk());
    }
}
void GameManager::EnterDoor(std::vector<Door>& aDoors)
{
    int input =  Library::SetInput(1, aDoors.size())-1;
    std::cout << "debug get dc from doors " << aDoors[0].GetDC() << std::endl;
}


Room& GameManager::PickDoor()
{
    const int input =  Library::SetInput(1, myDoors.size())-1;
    std::cout << "I didnt go int" << myDoors[input].GetPrevRoom().GetName() << std::endl;
    std::cout << "I am going into " << myDoors[input].GetNextRoom().GetName() << std::endl;
    Room& room = myDoors[input].GetNextRoom();
    std::cout << "debug get dc from doors " << myDoors[input].GetDC() << std::endl;
    return room;
}
void GameManager::SetCheatState(Player& aPlayer)
{
    while (myCheatState != CheatState::Exit)
    {
        const int min = static_cast<int>(CheatState::Exit);
        const int max  = static_cast<int>(CheatState::Count);
        const int input = Library::SetInput(min,max ); // get a setter
        if (input == 0)
        {
            std::cout << "You are exiting the Cheat Menu with these cheats here" << std::endl;
            if (aPlayer.GetGodMode()== true && aPlayer.GetInfinite() == true)
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
        }
        else if (input == 1)
        {
            if ( aPlayer.GetInfinite() == true)
            {
                aPlayer.SetInfinite(false);
                std::cout << "You turned off infinite damage" << std::endl;
            }
            
            else
            {
                aPlayer.SetGodMode(true);
                std::cout << "You have GodMode and cant be harmed" << std::endl;
            }
        }
        else if (input == 2)
        {
            if ( aPlayer.GetGodMode() == true)
            {
                aPlayer.SetInfinite(false);
                std::cout << "You turned off infinite damage" << std::endl;
            }
            
            else
            {
                aPlayer.SetInfinite(true);
                std::cout << "You turned on infinite damage" << std::endl;
            }
        }
        else if (input == 3)
        {
            if (aPlayer.GetGodMode() == true&& aPlayer.GetInfinite() == true)
            {
                aPlayer.SetInfinite(false);
                aPlayer.SetInfinite(false);
                std::cout << "You are turned off infinite damage and godmode" << std::endl;
            }
            else
            {
                aPlayer.SetGodMode(true);
                aPlayer.SetInfinite(true);
            }
            std::cout << "You are turned on infinite damage and godmode" << std::endl;
        }
        else
        {
            std::cout << "Your cheats are: " << std::endl;
        }
    }
}
void GameManager::PlayGame()
{
    
    EnterDoor(myDoors);
   
  
    
    while (myMainState != MainState::Exit && myPlayer.GetIsAlive())
    {
        PrintMainMenuChoices(myPlayer); //TODO below func in mainmenu?
        SetGameState(static_cast<MainState>(Library::SetInput(0,sizeof(MainState))));
        
        while (myPlayer.GetIsAlive() && myMainState != MainState::Exit)
        {
            switch (myMainState)
            {
            case  MainState::Exit:
                {
                    std::cout << "I am going out of game baii" << std::endl;
                    break;
                }
            case MainState::Play:
                {
                    {
                        std::cout << "Choose a room to test: 1, 2, 3" << std::endl;
                        Room* room = &PickDoor();
                
                        if (room->GetName() == myRoom0.GetName())
                        {
                  
                            PopulateEnemies(myPopulation, myEnemy0,  *room);
                        }
                        else if (room->GetName() == myRoom1.GetName())
                        {
                   
                            PopulateEnemies(myPopulation, myEnemy1,  *room);
                        }
                        else if (room->GetName() ==myRoom2.GetName())
                        {
                   
                            PopulateEnemies(myPopulation, myEnemy2, *room);
                        }
                
                        {
                            //myDoor0.GetNexRoom(myRoom1).EnterRoom(myPlayer);
                            room->ExploreRoom();
                            room->RoomMenuChoices(myPlayer);
                            //door->EnterDoor(room);
                            GameCombat();
                        }
              
                        system("pause");
                        std::cout << "I am outside of the room\n" << std::endl;
                    }
                    break;
                }
            case MainState::Cheats_Menu:
                {
                    std::cout << "You are in the  cheats menu\n" << std::endl;
                 
                    while (myMainState == MainState::Cheats_Menu)
                    {
                     std::cout  << "Select your cheat to toggle: \t1: Immortality \t2: Infinite Damage\n 3:" 
                        << "3: Both infinite and immortality \t0: Exit cheats with your choices" << std::endl;
                       
                       SetCheatState(myPlayer);
                    }
                    break;
                }
            case MainState::Main_Menu:
                {
                    break;
                }
            case MainState::Count:
                {
                    break;
                }
            default: ;
            }
            {
                std::cout << "I am main menu choices func  ending the game" << std::endl;
            }
           
         
        }
    }
}
