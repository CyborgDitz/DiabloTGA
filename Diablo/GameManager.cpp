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

void GameManager::PopulateSpells(std::vector<Spell>& aSpells)
{
    aSpells.push_back(mySpell0);
    aSpells.push_back(mySpell1);
    aSpells.push_back(mySpell2);

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

void GameManager::ChooseDoor()
{
    const int minInput = 1;
    const int doorAmount = myCurrentRoom->GetDoorAmount();
    bool isLocked = true;
    while (isLocked)
    {
        std::cout << "Pick a door! 1:next Room, 2: previous door" << std::endl;

        const int input = Library::SetInput(minInput, doorAmount - 1);

        Door* theTargetDoor = &myDoors[input];
        std::cout << "I am going from the " << myCurrentRoom->GetName() << " room to\n the room "
            << myCurrentDoor->GetNextRoom().GetName() << " and my prev room is " << myCurrentDoor->GetPrevRoom().
            GetName() << std::endl;
        if (input == 1)
        {
            myCurrentRoom = &myCurrentDoor->GetNextRoom();
        }
        else if (input == doorAmount)
        {
            myCurrentRoom = &myCurrentDoor->GetPrevRoom();
        }

        std::cout << "Entering " << myCurrentRoom->GetName() << std::endl;

        if (theTargetDoor->GetIsLocked() == true)
        {
            theTargetDoor->UnlockDoor(myPlayer);
            if (theTargetDoor->GetIsLocked() == true)
            {
                std::cout << "Door is still locked!" << std::endl;
                return;
            }

            if (theTargetDoor->GetIsLocked() == false)
                myCurrentDoor = theTargetDoor;
            std::cout << "Door is not locked!" << std::endl;
            return;
        }
        isLocked = false;
    }
}
void GameManager::CastSpell()
{
    Spell* theSpell =myCurrentSpell;
    int theMainMod = theSpell->GetMainMod();
    int theSecondMod = theSpell->GetSecondMod();
    bool isConsumed = theSpell->GetIsConsumed();
    int theTimer = theSpell->GetTimer();
    std::cout << "I am charged with "  << std::endl;
    switch (theSpell->GetElement())
    {
    case Spell::Element::None:
        {
            std::cout << "NUTHIN" << std::endl;
            break;
        }
    case Spell::Element::Fire:
        {
            std::cout << "Fire!!!" << std::endl;
            break;
        }
    case Spell::Element::Ice:
        {
            std::cout << "Ice!!!" << std::endl;
            break;
        }
    case Spell::Element::Blob:
        {
            std::cout << "... wait what. Wtf is this slime? It looks delicious" << std::endl;
            break;
        }
    case Spell::Element::Count:
        {
            break;
        }
    default: 
        ;
    }
    std::cout << "Stat Buffs: Main = " <<theMainMod << "and Secondary stat: "<< theSecondMod<< std::endl;
    
    if (isConsumed == true)
    {
        std::cout << "\n  only one turn!" <<std::endl;
    }
    else
    {
        std::cout << "\n and lasts for " << theTimer<<" turns!" <<std::endl;
    }
    SetHasSpell(false);
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
        if (GetHasSpell() == true)
        {
           
        }
        std::cout << "pick a target " << std::endl;
        const int target = Library::SetInput(1, myPopulation.size()) - 1;
        const int playerAtk = myPlayer.CalcPlayerAttack();

        myPopulation[target].TakeDamage(playerAtk);

        if (myPopulation[target].GetIsAlive() == false)
        {
            myPopulation.erase(myPopulation.begin() + target);
        }
        for (int i = 0; i < myPopulation.size(); i++)
        {
            int mobAtk = myPopulation[i].GetAtk();
            myPlayer.TakeDamage(mobAtk);
        }
    }
}

void GameManager::StartRoomLoop()
{
    myCurrentRoom = &myRooms[0];
    myCurrentDoor = &myDoors[0];
    PopulateRoom();
    while (myPlayer.GetIsAlive() && myRoomState != RoomState::Exit)
    {
        {
            std::cout << "I am in room: " << myCurrentRoom->GetName() << std::endl;
            myCurrentRoom->PrintRoomData(&myPopulation);
            SelectRoomMenuChoices();
            //call from room like print etc
            switch (myRoomState)
            {
            case RoomState::Exit :
                break;
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
                    break;
                }
            case RoomState::Explore :
                {
                   
                   
                    if (myCurrentRoom->GetHasChest()== true && myCurrentRoom->GetHasItems() == true )
                    {
                        std::cout << "I found an item in the chest!" << std::endl;
                        myCurrentRoom->SetHasChest(false);
                       
                    }
                    else if (myCurrentRoom->GetHasItems() == true)
                    {
                        std::cout << "I found an item on the floor!" << std::endl;
                    }
                    else
                    {
                        std::cout << "There is nothing here..." << std::endl;
                        return;
                    }
                    myCurrentRoom->SetHasItems(false);
                    myPlayer.PopulateInventory(myCurrentRoom->GetItem());
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

void GameManager::RemoveFromSpells(Spell& aSpell)
{
    if (mySpells.empty()==true)
    {
        std::cout << "There is no power in the room!" << std::endl;
        return;
    }
    
    for (int i = 0; i < mySpells.size(); i++)
    { 
       
        bool removeItem = strcmp(mySpells[i].GetName(), aSpell.GetName()) == 0;
        if (removeItem)
        {
            std::cout << "I removed spell " << aSpell.GetName() << " from the spellbook" << std::endl;
            mySpells.erase(mySpells.begin() + i);
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
