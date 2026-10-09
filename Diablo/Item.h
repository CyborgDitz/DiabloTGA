#pragma once
#include <string.h>
class Item
{   
public:
    Item( const char* aName,  int aMainMod,  int aSecondMod)   
    {
        strcpy_s(myName, aName);
        myMainMod = aMainMod;
        mySecondMod = aSecondMod;
    }


    const char* GetName() const { return myName; }
    int GetMainMod() const { return myMainMod; }
    int GetSecondModifier() const { return mySecondMod; }
  
    void PrintStats() const;

private:
    char myName[31] = {};
    int myMainMod {};
    int  mySecondMod{};
  
};
