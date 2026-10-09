#pragma once

#include <string.h>

class Spell
{
public:
    enum  Element
    {
        None = 0,
        Fire = 1,
        Ice = 2,
        Blob = 3,
        Count = 4
    }; 
    Spell( const char* aName, const int aMainMod, const int aSecondMod, const bool aIsConsumed, const int aTimer, const Element aElement)
    { 
        strcpy_s(myName, aName);
        myMainMod = aMainMod;
        mySecondMod = aSecondMod;
        myIsConsumed= aIsConsumed;
        myTimer = aTimer;
        myElement = aElement;
    }
    
    const char* GetName() { return myName; }
    int GetMainMod() { return myMainMod; }
    int GetSecondMod() { return mySecondMod; }
    bool GetIsConsumed() { return myIsConsumed; }
    int GetTimer()
    {
        if (myIsConsumed == false)
        {
        return myTimer;
        }
        else
        {
           myTimer = 0;
        }
    }
    
    Element& GetElement() { return myElement; }
   
private:
    char myName[23] = {};
    int myMainMod {};
    int  mySecondMod{};
    bool myIsConsumed{};
    int myTimer {};
    
    Element myElement = None;
   
};
