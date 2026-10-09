#pragma once


#include "GameManager.h"
#include "Item.h"

class Chest
{   
public:
   

   Chest(bool isUnopened,bool aHasItem, bool aHasSpell, const Item& aItem)
       :myItem(aItem)
    {
       myIsUnopened = isUnopened;
       myHasItem = aHasItem;
       myHasSpell = aHasSpell;
    }
    

   bool GetHasItem() const {return myHasItem;}
    bool GetHasSpell() const {return myHasSpell;}
    bool GetIsUnopened() const {return myIsUnopened;}
  
    Item& GetItem(){return myItem;}
    void PrintStats() const;
    void LootChest(Player& aPlayer, Room* aRoom);

private:
    Item myItem;
    bool myIsUnopened;
    bool myHasItem;
    bool myHasSpell;

    bool aHasSpell;
  
};

