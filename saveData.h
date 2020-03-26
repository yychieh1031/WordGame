#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>

#include"characterDetail.h"

#ifndef _SAVEDATA_H_
#define _SAVEDATA_H_

class saveData : public character{
    private:
        char charSave[1024];
        std::fstream data;
        std::vector<std::string> detail;
        std::string buff;
    public:
        
        void setCharacterDetail(character user){
            detail.push_back(user.getName());
            detail.push_back(",");
            detail.push_back(std::to_string(getHealth()));
            detail.push_back(",");
            detail.push_back(std::to_string(getPower()));
            detail.push_back(",");
            detail.push_back(std::to_string(getDefence()));
            detail.push_back(",");
            detail.push_back(std::to_string(getExp()));
        }
        void save(std::string userName){
            userName.append(".text");
            data.open(userName,std::ios::out|std::ios::trunc);
            for(auto const& i: detail){
                data << i;
            }
        }
        void close(){
            data.close();
            std::cout<<"Next round?(Y\\N)\n";
        }
};
#endif