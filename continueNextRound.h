#include <iostream>
#include <string>

#include "battle_result.h"
#include "characterDetail.h"
#include "monsterDetail.h"
class continueNextRound{
    private:
        int round;
        result vs;
        character user;
        monsterDetail monster;    
    public:
        void nextRound(std::string userInPut, battle& battle1, battle& battle2){
            while(true){
                if(userInPut.compare("N")==0||userInPut.compare("n")==0){
                    break;
                }
                

                vs.startFight(battle1,battle2);
                std::cout<<"Next round?(Y\\N)\n";
                std::getline(std::cin,userInPut);
            }
        }

};