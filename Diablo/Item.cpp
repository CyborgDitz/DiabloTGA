#include "Item.h"

#include <iostream>

void Item::PrintStats() const
{
    std::cout << "The Item: "<< myName << " stats are : \n " <<
        "Affects MainStat by : " << myMainStat<< '\t' <<
        "Affects MainStat by " << mySecondaryStat << '\n' << std::endl;
}
