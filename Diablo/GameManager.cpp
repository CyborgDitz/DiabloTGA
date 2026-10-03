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

void GameManager::EnterMainMenu(Player& aPlayer)
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
    int choice = Library::SetInput(min, sizeof(myState));
    myState = static_cast<MainState>(choice);
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
    int input =  Library::SetInput(1, myDoors.size())-1;
    std::cout << "I didnt go int" << myDoors[input].GetPrevRoom().GetName() << std::endl;
    std::cout << "I am going into " << myDoors[input].GetNextRoom().GetName() << std::endl;
    Room& room = myDoors[input].GetNextRoom();
    std::cout << "debug get dc from doors " << myDoors[input].GetDC() << std::endl;
    return room;
}
void GameManager::PlayGame()
{
    
    EnterDoor(myDoors);
    PickDoor();
    system("pause");
    bool isMenu = true; //mainstate enum menu
    
    while (GetMainState() != MainState::Exit && isMenu && myPlayer.GetIsAlive())
    {
        EnterMainMenu(myPlayer); //TODO below func in mainmenu?
        SetGameState(static_cast<MainState>(Library::SetInput(0,sizeof(MainState))));
        
        while (myPlayer.GetIsAlive() && isMenu) //TODO could be func?
        {
            if (GetMainState() == MainState::Exit)
            {
                std::cout << "I am main menu choices func  ending the game" << std::endl;
            }
            else if (GetMainState() == MainState::Play)
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
        }
    }
}
