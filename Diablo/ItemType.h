#pragma once
#include <string.h>

class ItemType
{  
  
public:
    ItemType( const char* aName,  int aMainMod,  int aSecondMod);


    const char* GetName() const { return myName; }
    int GetMainMod() const { return myMainMod; }
    int GetSecondMod() const { return mySecondMod; }
    void SetName(const char* aName) { strcpy_s(myName, aName); }
    void SetMainMod(int aMainMod) { myMainMod = aMainMod; }
    void SetSecondMod(int aSecondMod) { mySecondMod = aSecondMod; }
  
    void PrintStats() const;
 
private:
    char myName[31] = {};
    int myMainMod {};
    int  mySecondMod{};
  
};
