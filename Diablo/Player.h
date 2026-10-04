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
        myHealth = myMaxHealth;
        myCarryCap = myStr + (myDex*3);
        myDefense = myVit + (myDex);
    } 
    void PrintStats() const;
    int GetAtk() const {return myAtk;}
    int GetStr() const { return myStr;}
    int GetDex( ) const { return myDex;}
    int GetVit() const {return myVit;}
    int GetHealth() const {return myHealth;}
    int GetIsAlive() const {return myAtk;}
    int GetMaxHealth() const {return myMaxHealth;}
    int GetCarryCap() const {return myCarryCap;}
    int GetDefense() const {return myDefense;}
    const char* GetName() const { return myName; }
    bool GetInfinite() const {return hasInfinite;}
    bool GetGodMode() const {return hasGodMode;}
    
   void SetInfinite(bool aBool) {hasInfinite = aBool;}
    void SetGodMode(bool aBool){hasGodMode = aBool;}
    void TakeDamage(int aDamage);
    void SetName();
    bool GetIsAlive(){return myIsAlive;}

private:
    
  //  const char* myName[17] = {}; not MVP
    char myName[17] = {};
    int myStr{};
    int myDex{};
    int myVit{};
    int myHealth{};
    int myAtk{};
    int myMaxHealth{};
    int myCarryCap{};
    int myDefense{};
  
    bool myIsAlive = true;
    bool hasGodMode = false;
    bool hasInfinite = false;
};
