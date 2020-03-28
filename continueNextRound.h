#include <iostream>
#include <string>
#include <windows.h>

#include "battle_result.h"
#include "characterDetail.h"
#include "monsterDetail.h"
#include "weapon.h"
class continueNextRound{
    private:
        int round;
        result vs;
        character user;
        monsterDetail monster;
        randomWeapon detail;
        std::string userInsert;    
    public:

        void nextRound(std::string userInPut, battle& battle1, battle& battle2, int randomInt){
            while(true){
                if(userInPut.compare("N")==0||userInPut.compare("n")==0){
                    break;
                }
                
                vs.startFight(battle1,battle2);
                std::cout<<"Next round?(Y\\N)\n";
                std::getline(std::cin,userInPut);
            }    
        }
        std::string searching(std::string userInPut){
            
            for(int i{0}; i<5; i++){
                        Sleep(1000);
                        std::cout<<"Searching..";
                    }
                    std::cout<<"\nFind a weapon!!\n";
                    detail.showWeaponDetail();
                    std::cout<<"Continue searching?(Y\\N)\n";
                    std::getline(std::cin,userInPut);
                    return this->userInsert = userInPut;
                       
        }
        std::string getUserInset(){return userInsert;}

};