#include "Player.h"

#include <iostream>

#include "Room.h"

void Player::PrintStats() const
{
    std::cout << myName << "stats are : \n " <<
        "Current HP: " << myHealth << '\t' <<
        "MaxHP: " << myMaxHealth << '\n' << 
        "Atk: " << myAtk << '\t' <<  
        "Def: " << myDefense << '\n' << 
        "STR: " << myStr << '\t' <<
        "DEX: " << myDex << '\t' <<
        "VIT " << myVit << '\t' <<
        "Carrying Cap: " << myCarryCap << '\n' <<std::endl;
}




void Player::PopulateInventory(Item& aItem)
{  
    const int myInventorySize = myInventory.size()+1;
    for (int i = 0; i < myInventorySize ; i++)
    {
        myInventory.push_back(aItem);
    }
    //myInventory.push_back(aItem);
}

void Player::RemoveFromInventory(Item& aItem)
{
    if (myInventory.empty()==true)
    {
        std::cout << "I have no items in my inventory" << std::endl;
        return;
    }
    
    for (int i = 0; i < myInventory.size(); i++)
    { 
        const char* myInvItem = myInventory[i].GetName();
        const char * targetItem = aItem.GetName();
        //bool removedItem = myInventory[i].GetName() == aItem.GetName();
        
        //if (removedItem)
        bool removeItem = strcmp(myInventory[i].GetName(), aItem.GetName()) == 0;
        if (removeItem)
        {
            std::cout << "I removed item " << aItem.GetName() << " from inventory" << std::endl;
            myInventory.erase(myInventory.begin() + i);
        }
    }
}


void Player::TakeDamage(const int aDamage)
{
    //todo same func for monster and myPlayer
    if (hasGodMode == true)
    {
        std::cout << "I am a god! " << std::endl;
        return;
    }
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << "Player " << myName << " has currently " << myCurrentHealth << " health\n" <<
       " and takes " << aDamage << ". Now has " << myHealth <<  
           " health left!" <<std::endl;
    
    if (myHealth <= 0)
    {
        myIsAlive = false;
        std::cout << "I am dead and game ends bleh.." << std::endl;
        system("pause");
        return;
    }
    std::cout << "I am still standing!" << std::endl;
}

