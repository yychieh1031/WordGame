#include <iostream>
#include <string>
#include <ctime>

#ifndef _WEAPON_H_
#define _WEAPON_H_
class randomWeapon{
    private:
        std::string weaponName;
        int weaponPower;
    public:
        std::string getWeaponName(){return weaponName;}
        void setWeaponName(std::string weaponName){this->weaponName = weaponName;}
        int getWeaponPower(){return weaponPower;}
        void setWeaponPower(int weaponPower){this->weaponPower = weaponPower;}
        void showWeaponDetail(){
            std::cout<<"Weapon Name: "<< weaponName << std::endl;
            std::cout<<"Weapon Power: "<< weaponPower << std::endl;
        }
};
#endif 