#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <windows.h>

#include "characterDetail.h"
#include "monsterDetail.h"
#include "battle_result.h"
#include "continueNextRound.h"
#include "weapon.h"
#include "saveData.h"
int main(){
    srand(time(NULL));
    std::cout<<"Welcome to zombie world.\n";
    std::cout<<"This game only u to enter somethin to play.\n";
    std::cout<<"First of all, you should enter your character name.\n";
    character user;
    saveData save;
    result toUser;
    continueNextRound nextRound;
    monsterDetail monster;
    randomWeapon weapon;
    int randomInt = rand() % 2;
    int randomWeaponPower = rand()% 4 + 1;
    std::string name, userInsert;

    std::getline(std::cin,name);
    user.setName(name);
    user.toUser();
    save.setCharacterDetail(user);
    save.save(name);


    battle userCharacter(user.getName(),user.getHealth(),user.getPower(),user.getDefence());
    battle monsterName(monster.getName(),monster.getHealth(), monster.getPower(), monster.getDefence());
    std::cout<<"You have two way to go market(search) and street(fight).\n";
    std::getline(std::cin,userInsert);
    //toUser.startFight(userCharacter,monsterName);
    save.close();
    //std::getline(std::cin,userInsert);
    while(true){
        if(userInsert.compare("fight")==0||userInsert.compare("street")==0){
            nextRound.nextRound(userInsert,userCharacter,monsterName,randomInt);
            std::cout<<"Where you wanna go?(market/street)\n";
            std::getline(std::cin,userInsert);
            nextRound.getUserInset();
        }else if(userInsert.compare("market")==0||userInsert.compare("search")==0){
            weapon.setWeaponName("Pistol");
            weapon.setWeaponPower(randomWeaponPower);
            nextRound.searching(userInsert);
            std::cout<<"Where you wanna go?(market/street)\n";
            std::getline(std::cin,userInsert);
            nextRound.getUserInset();
        }else{
            break;
        }
    }
    save.getLoadDetail();
    
    return 0;
}