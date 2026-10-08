#pragma once
#include <string.h>

class Item
{
public:
    Item( const char* aName, const int aModifier, const int aMainStat, const int aSecondaryStat) 
    : myModifierValue(0), myMainStat(0), mySecondaryStat(0)
    {
        strcpy_s(myName, aName);
        int myModifierValue = aModifier;
        int myMainStat = aMainStat;
        int mySecondaryStat = aSecondaryStat;
    }


    const char* GetName() const { return myName; }
    int GetModifier() const { return myModifierValue; }
    int GetMainStat() const { return myMainStat; }
    int GetSecondaryStat() const { return mySecondaryStat; }
    void PrintStats() const;

private:
    char myName[17] = {};
    int myModifierValue;
    int myMainStat;
    int mySecondaryStat;
    bool myIsAlive = true;
};
