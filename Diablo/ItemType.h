#pragma once
#include <string.h>
class ItemType
{   
  
public:
    ItemType( const char* aName,  int aMainMod,  int aSecondMod)   
    {
        strcpy_s(myName, aName);
        myMainMod = aMainMod;
        mySecondMod = aSecondMod;
    }


    const char* GetName() const { return myName; }
    int GetMainMod() const { return myMainMod; }
    int GetSecondModifier() const { return mySecondMod; }
    void SetName(const char* aName) { strcpy_s(myName, aName); }
    void SetMainMod(int aMainMod) { myMainMod = aMainMod; }
    void SetSecondModifier(int aSecondMod) { mySecondMod = aSecondMod; }
  
    void PrintStats() const;
 
private:
    char myName[31] = {};
    int myMainMod {};
    int  mySecondMod{};
  
};
