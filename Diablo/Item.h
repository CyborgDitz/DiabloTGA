#pragma once
#include "ItemType.h"

enum class enumItemType
{
    Hammer,
    Sword,
    Horn,
    Count
};
class Item
{
public:
    Item(const ItemType& aItemType);
    int GetMainMod() const;
    int GetSecondMod() const;
    const char* GetName() const;

private:
    const ItemType* myItemType;
};
