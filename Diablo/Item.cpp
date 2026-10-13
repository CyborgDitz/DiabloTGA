#include "Item.h"
Item::Item(const ItemType& aItemType) : myItemType(nullptr) { }
int Item::GetMainMod() const
{
    return myItemType->GetMainMod();
}

int Item::GetSecondMod() const
{
    return myItemType->GetSecondMod();
}

const char* Item::GetName() const
{
    return myItemType->GetName();
}
