#include "Item.h"

#include <iostream>

void Item::PrintStats() const
{
    std::cout << "The Item - "<< myName << " - stats are : \n" <<
        "Affects MainStat by: " << myMainMod << '\t' <<
        "Affects Secondary Stat by: " << mySecondMod << '\n' << std::endl;
}
