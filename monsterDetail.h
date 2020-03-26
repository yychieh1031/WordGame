#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <windows.h>

#ifndef _MONSTERDETAIL_H_
#define _MONSTERDETAIL_H_
class monsterDetail{
    private:
        std::string monster = "Zombie";
        int health = 100;
        int power = 20;
        int defence = 15;
    public:
        std::string getName(){return monster;}
        int getHealth(){return health;}
        int getPower(){return power;}
        int getDefence(){return defence;}
        
};


#endif