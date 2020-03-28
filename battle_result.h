#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <windows.h>

#include "characterDetail.h"
#include "monsterDetail.h"

#ifndef _BATTLE_RESULT_H_
#define _BATTLE_RESULT_H_
class battle{
    private:
        int power;
        int defence;
    public:
        std::string charName;
        int health;
        battle(std::string charName, int health, int power, int defence){
            this->charName = charName;
            this->health = health;
            this->power = power;
            this->defence = defence;
        }
        int attack(){
            return std::rand() % this->power;
        }
        int block(){
            return std::rand() % this->defence;
        }
        
};

class result{
    private:
        character user;
        monsterDetail monster;
    public:
        void startFight(battle& battle1, battle& battle2){
            while(true){
                Sleep(1000);
                if(result::getAttackResult(battle2, battle1).compare("Game over")==0){
                    std::cout<<"Game over\n";
                    battle1.health = 100;
                    battle2.health = 30;
                    break;
                }
                if(result::getAttackResult(battle1, battle2).compare("Game over")==0){
                    std::cout<<"You win\n";
                    battle1.health = 100;
                    battle2.health = 30;
                    break;
                }
            }
        }
        std::string getAttackResult(battle& battleA, battle& battleB){
            int aAttackAmt = battleA.attack();
            int bDefenceAmt = battleB.block();
            int damage2B = ceil(aAttackAmt - bDefenceAmt);

            damage2B = (damage2B <= 0) ? 0 : damage2B;
            battleB.health = battleB.health - damage2B;
            std::cout<<battleA.charName<<" attacks "<<battleB.charName<<" and deals "<<damage2B<<" damage.\n";
            std::cout<<battleB.charName<<" is down to "<<battleB.health<<" health.\n"; 
    
            if(battleB.health <= 0){
                return "Game over";
            }else{
                return "Next round.";
            }
        }
};
#endif