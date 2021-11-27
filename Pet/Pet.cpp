//  Student ID: 20399730
//  Pet.cpp
//  Quest 6
//  2a-Lab-06
//  Created by Victor Castor on 7/28/20.
//  Copyright © 2020 Victor Castor. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>

#include "Pet.h"

using namespace std;

//static size_t _population;
// This is a way to properly initialize (out-of-line) a static variable. size_t Pet::_population = 0;
size_t Pet::_population = 0;

Pet::Pet(string name, long id, int num_limbs)
{
    _name = name;
    _id = id;
    _num_limbs = num_limbs;
    _population++;
}
Pet::~Pet()
{
    _population--;
}
string Pet::get_name() const
{
    return _name;
}
long Pet::get_id() const
{
    return _id;
}
int Pet::get_num_limbs() const
{
    return _num_limbs;
}
bool Pet::set_name(string name)
{
    if (name == "")
        return false;
    
    _name = name;
    return true;
}
bool Pet::set_id(long id)
{
    if(id < 0)
        return false;
    
    _id = id;
    return true;
}
bool Pet::set_num_limbs(int num_limbs)
{
    if(num_limbs < 0)
        return false;
    
    _num_limbs = num_limbs;
    return true;
}
string Pet::to_string() const
{
    string info = "";
    info += "(Name: " + _name + ", ID: " + ::to_string(_id) + ", Limb Count: " + ::to_string(_num_limbs) + ")";
    return info;
}
// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len)
{
    pets.resize(n);
    long prev_id = 0;
    for (size_t i = 0; i < n; i++)
    {
        long id = prev_id + 1 + rand() % 10;
        pets[i].set_id(id);
        pets[i].set_num_limbs(rand() % 9); // up to arachnids
        pets[i].set_name(make_a_name(name_len));
        prev_id = id;
    }
}
// ---------------------------------------------------------------------
string Pet::make_a_name(int len)
{
    string randomName = "";
    string vowels = "aeiou";
    string consonants = "bcdfghjklmnpqrstvwxyz";
    int before = 0;
    
    before = rand();
    for (int i = 0; i < len; i++) {
        if (before % 2 == 0) {
            randomName += consonants[rand() % consonants.length()];
        }
        else {
            randomName += vowels[rand() % vowels.length()];
        }
        before++;
    }
    return randomName;
}
// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2)
{
    if(pet1.get_name()==pet2.get_name())
    {
        if (pet1.get_id()==pet2.get_id())
            {
                if(pet1.get_num_limbs()==pet2.get_num_limbs())
                {
                    return true;
                }
            }
    }
    return false;
}
    
bool operator!=(const Pet& pet1, const Pet& pet2)
{
    if(pet1.get_name()==pet2.get_name())
    {
        if (pet1.get_id()==pet2.get_id())
        {
            if(pet1.get_num_limbs()==pet2.get_num_limbs())
            {
                return false;
            }
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const Pet& pet)
{
    os<<pet.to_string();
    return os;
}
