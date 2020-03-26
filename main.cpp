#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <windows.h>

#include "characterDetail.h"
#include "monsterDetail.h"
#include "battle_result.h"
#include "continueNextRound.h"
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

    std::string name, userInsert;

    std::getline(std::cin,name);
    user.setName(name);
    user.toUser();
    save.setCharacterDetail(user);
    save.save(name);


    battle userCharacter(user.getName(),user.getHealth(),user.getPower(),user.getDefence());
    battle monsterName(monster.getName(),monster.getHealth(), monster.getPower(), monster.getDefence());
    toUser.startFight(userCharacter,monsterName);
    save.close();
    std::getline(std::cin,userInsert);
    nextRound.nextRound(userInsert,userCharacter,monsterName);

    
    return 0;
}