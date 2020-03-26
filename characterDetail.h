#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <windows.h>

#ifndef _CHARACTERDETAIL_H_
#define _CHARACTERDETAIL_H_
class character{
    private:
        std::string charName;
        int health = 100;
        int power = 20;
        int defence = 15;
        int exp = 50;
    public:
        std::string getName(){return charName;}
        void setName(std::string charName){this->charName = charName;}
        int getHealth(){return health;}
        int getPower(){return power;}
        int getDefence(){return defence;}
        int getExp(){return exp;}
        int resetValue(int health){return health = 100;}
        character(std::string charName);
        character();
        void toUser();
};

character::character(std::string charName){
    this->charName = charName;
}
character::character(){
    this->charName = "Mr.nobody";
}
void character::toUser(){
    std::cout<<"The character name is "<<this->charName<<std::endl;
}

#endif