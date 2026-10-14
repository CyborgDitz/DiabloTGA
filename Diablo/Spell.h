#pragma once
#include <string.h>
class Spell
{   
public:
   Spell( const char* aName, const int aMainMod, const int aSecondMod, const bool aHasSpellSlot)   
    {
        strcpy_s(myName, aName);
        myMainMod = aMainMod;
        mySecondMod = aSecondMod;
        hasSpellSlot = aHasSpellSlot;
    }


    const char* GetName() const { return myName; }
    int GetMainMod() const { return myMainMod; }
    int GetSecondModifier() const { return mySecondMod; }
    bool GetHasSpellSlot() const { return hasSpellSlot; }
  
    void PrintStats() const;

private:
    char myName[31] = {};
    int myMainMod {};
    int  mySecondMod{};
    bool hasSpellSlot = false;
  
};
