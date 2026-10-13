#pragma once
#include <array>

#include "Item.h"
#include "ItemType.h"

class ItemFactory
{
    public:
  
    void Init();
    
    Item CreateItem(const enumItemType aItemType) const;
    
    private:
    std::array<ItemType, static_cast<int>(enumItemType::Count)> myItemTypes;

};
