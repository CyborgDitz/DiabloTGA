#include "GameManager.h"
#include <iostream>
#include <ostream>
#include "Library.h"

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

void GameManager::PopulateRooms()
{
    myRooms.push_back(myRoom0);
    myRooms.push_back(myRoom1);
     myRooms.push_back(myRoom2);
    // std::cout<< "debug There are " << aRooms.size() << " rooms" << std::endl; 
}

void GameManager::PopulateDoors()
{
    myDoors.push_back(myDoor0);
    myDoors.push_back(myDoor1);
    myDoors.push_back(myDoor2);

    //std::cout<< "debug There are " << aDoors.size() << " doors" << std::endl; 
}

void GameManager::PopulateEnemies(std::vector<Enemy>& aPopulation, Enemy& aEnemyType, Room& aRoom)
{
    int enemiesAmount = aRoom.GetEnemiesAmount();
    for (int i = 0; i < enemiesAmount; i++)
    {
        aPopulation.push_back(aEnemyType);
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
        myCheatState  = static_cast<CheatState>(Library::SetInput(min, max)); // get a setter
        switch (myCheatState )
        {
        case CheatState::Exit :
            {
                std::cout << "You are exiting the Cheat Menu" << std::endl;
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
                    aPlayer.SetGodMode(false);
                    std::cout << "You have turned off infinite damage and godmode" << std::endl;
                }
                else
                {
                    aPlayer.SetGodMode(true);
                    aPlayer.SetInfinite(true);
                    std::cout << "You have have on infinite damage and godmode" << std::endl;
                }
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
            {
                break;
            }
        default :
            {
                std::cout << "not that one" << std::endl;
                break;
            }
        }
    }
}

void GameManager::ChooseDoor()
{
    const int minInput = 1;
    const int doorAmount = myCurrentRoom->GetDoorAmount();
   
    bool isLocked = true;
    while (isLocked)
    {
        std::cout << "Pick a door! 1:next Room "<< myCurrentDoor->GetNextRoom().GetName()<<
        ", 2: previous door"<< myCurrentDoor->GetPrevRoom().GetName()<< std::endl;

        int input = (Library::SetInput(minInput, doorAmount));
        
        std::cout << "Entering " << myCurrentRoom->GetName() << std::endl;
       
        if (input == 1)
        {
            myCurrentRoom= &myCurrentDoor->GetNextRoom();
            
        }
        else if (input == 2)
        {
            myCurrentRoom= &myCurrentDoor->GetPrevRoom();
        }
        if (myCurrentDoor->GetIsLocked() == true)
        {
            myCurrentDoor->UnlockDoor(myPlayer);
            if (myCurrentDoor->GetIsLocked() == true)
            {
                std::cout << "Door is still locked!" << std::endl;
                return;
            }

            if (myCurrentDoor->GetIsLocked() == false)
               
            std::cout << "Door is not locked!" << std::endl;
            return;
        }
        for (int i = 0; i < myRooms.size(); i++)
        if (strcmp(myCurrentDoor->GetNextRoom().GetName(), myRooms[i].GetName())== 0)
        {
           
        }
       
        isLocked = false;
    }
      
}

bool GameManager::isEnemiesHere() const
{
    if (myPopulation.empty() == false)
    {
        std::cout << "There are Enemies!! Watch out! \n"
            << "you have to fight!" << std::endl;
        return true;
    }
    else
    {
        std::cout << " The room has no monsters! " << std::endl;
        return false;
    }
}

void GameManager::SelectRoomMenuChoices()
{
    {
        std::cout << "These are the choices" << std::endl;
        std::cout << "1: Open Door\t 2: Attack the Monsters!\t 3: Cast spells!\t 4: Explore The Room and Loot\t  5: See your stats\t" << std::endl;
        const int minInput = static_cast<int>(CheatState::Exit);
        const int maxInput = static_cast<int>(CheatState::Count);
        const int input = Library::SetInput(minInput, maxInput);
        myRoomState = static_cast<RoomState>(input);
    }
}

void GameManager::PopulateRoom()
{
    {
        if (myCurrentRoom->GetName() == myRooms[0].GetName())
        {
            PopulateEnemies(myPopulation, myEnemy0, myRooms[0]);
        }
        else if (myCurrentRoom->GetName() == myRooms[1].GetName())
        {
            PopulateEnemies(myPopulation, myEnemy1, myRooms[1]);
        }
        else if (myCurrentRoom->GetName() == myRooms[2].GetName())
        {
            PopulateEnemies(myPopulation, myEnemy2, myRooms[2]);
        }
    }
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
        
        //player turn
       
        
        std::cout << "pick a target " << std::endl;
        const int target = Library::SetInput(1, myPopulation.size()) - 1;
       
         int playerAtk = myPlayer.CalcPlayerAttack();

        myPopulation[target].TakeDamage(playerAtk);

        //enemy phase
        if (myPopulation[target].GetIsAlive() == false)
        {
            myPopulation.erase(myPopulation.begin() + target);
        }
        
        for (int i = 0; i < myPopulation.size(); i++)
        {
            const int mobAtk = myPopulation[i].GetAtk();
            myPlayer.TakeDamage(mobAtk);
        }
    }
}

void GameManager::StartRoomLoop()
{
    myCurrentRoom = &myRooms[0];
    myCurrentDoor = &myDoors[0];
  
    myPlayer.PopulateSpells(myCurrentRoom->GetSpell());
    PopulateRoom();
    while (myPlayer.GetIsAlive() && myRoomState != RoomState::Exit)
    {
       
        Spell& theRoomSpell = myCurrentRoom->GetSpell(); 
        
        system("cls");
        {
            std::cout << "I am in room: " << myCurrentRoom->GetName() << std::endl;
            myCurrentRoom->PrintRoomData(&myPopulation);
            SelectRoomMenuChoices();
            //call from room like print etc
            switch (myRoomState)
            {
            case RoomState::Exit :
                {
                    break;
                }
            case RoomState::OpenDoor :
                {
                    if (isEnemiesHere() == true)
                    {
                        break;
                    }
                    else
                    {
                        std::cout << "I am opening the doors" << std::endl;
                        ChooseDoor();
                        
                        PopulateRoom();
                    }
                    myPlayer.RemoveSpell();
                    myPlayer.PopulateSpells(myCurrentRoom->GetSpell());
                    break;
                }
            case RoomState::Combat :
                {
                    if (isEnemiesHere() == false)
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
            case RoomState::CastMagic:
                {
                    std::cout<< "I cast the spell for the next monster" << std::endl;
                    if (myCurrentRoom->GetHasSpell()==true)
                    {
                        myCurrentRoom->SetHasSpell( false);
                        myPlayer.CastSpell();
                    }
                    break;
                }
            case RoomState::Explore :
                {
                    if (myCurrentRoom->GetHasItems() == true && myPopulation.size() > 0)
                    {
                        std::cout << "The monster blocks the item on the floor!" << std::endl;
                        break;
                    }
                    else if (myCurrentRoom->GetHasChest()== true && myCurrentRoom->GetHasItems() == true )
                    {
                        std::cout << "I found an item in the chest!" << std::endl;
                        myCurrentRoom->SetHasChest(false);
                       
                    }
                    else if ( myCurrentRoom->GetHasItems() == true)
                    {
                        std::cout << "I found an item on the floor!" << std::endl;
                    }
                    else
                    {
                        std::cout << "There is nothing here..." << std::endl;
                       break;
                    }
                    myCurrentRoom->SetHasItems(false);
                    myPlayer.PopulateInventory(myCurrentRoom->GetItem());
                    std::cout << "I took the " << myCurrentRoom->GetItem().GetName() << " and put it into my inventory." << std::endl;
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
                std::cout << "I enter the dungeon to room " << myCurrentRoom->GetName() << std::endl;
                StartRoomLoop();
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
                std::cout << "I am main menu choices again and want to maybe enter the dungeon" << std::endl;
                break;
            }
        case MainState::Count :
            {
                break;
            }
        default :
            {
                break;
            }
        }
    }
}
