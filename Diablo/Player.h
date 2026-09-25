#pragma once

class Player
{
public:
    Player(const int aMyStr, const int aMyVit, const int aMyDex)
    {
        myStr=aMyStr;
        myDex=aMyDex;
        myVit=aMyVit;
        myAtk= (myStr*myDex);
        myMaxHealth= (myVit*4) + (myStr*6) + (myDex*3);
        myCarryCap = myStr + (myDex*3);
        myDefense = myVit + (myDex);
    } 
    void PrintStats();
    int GetStr() const { return myStr;}
    int GetDex( ) const { return myDex;}
    int GetVit() const {return myVit;}
    int GetHealth() const {return myHealth;}
    int GetAtk() const {return myAtk;}
    int GetMaxHealth() const {return myMaxHealth;}
    int GetCarryCap() const {return myCarryCap;}
    int GetDefense() const {return myDefense;}

private:
    
  //  const char* myName[17] = {}; not MVP
    int myStr{};
    int myDex{};
    int myVit{};
    int myHealth{};
    int myAtk{};
    int myMaxHealth{};
    int myCarryCap{};
    int myDefense{};
};
