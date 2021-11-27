// Student ID: 20399730
// Pet_Store.cpp
#include <iostream>
#include <sstream>
#include <vector>
#include "Pet_Store.h"

using namespace std;

Pet_Store::Pet_Store(size_t n)
{
    _pets.resize(n);
    _sort_order = NONE;
}
void Pet_Store::set_size(size_t n)
{
    _pets.resize(n);
}
size_t Pet_Store::get_size() const
{
    return _pets.size();
}
void Pet_Store::clear()
{
    _pets.clear();
}
void Pet_Store::populate_with_n_random_pets(size_t n)
{
    _sort_order = BY_ID;
    Pet::get_n_pets(n, _pets, 7);
}
// These two functions can be conveniently made anonymous "lambda" functions // defined within the scope of the functions where they're used (but only
// c++-11 on. For now we're just going to leave them here. It's straightforward
// to move them in. Just look up c++ lambda functions if you want. If you want
// to know but don't understand it, I'm happy to explain what they are. Ask me
// in the forums. It's not necessary to know about it to ace this course.
//
// You are free to experiment by hacking the functions below, but restore their
// correct functionalities before submitting your lab.
//
bool Pet_Store::_id_compare(const Pet& p1, const Pet& p2)
{
    return p1.get_id() < p2.get_id();
}

bool Pet_Store::_name_compare(const Pet& p1, const Pet& p2)
{
    return p1.get_name() < p2.get_name();
}

void Pet_Store::_sort_pets_by_id()
{
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_id_compare);
    _sort_order = BY_ID;
}

void Pet_Store::_sort_pets_by_name()
{
    std::sort(_pets.begin(), _pets.end(), Pet_Store::_name_compare);
    _sort_order = BY_NAME;
}

bool Pet_Store::find_pet_by_id_lin(long id, Pet& pet)
{
    int count = 0;
    while (_pets[count].get_id() != id)
    {
        if (count + 1 == _pets.size())
        {
            return false;
        }
        count++;
    }
    pet = _pets[count];
    return true;
}

bool Pet_Store::find_pet_by_name_lin(string name, Pet& pet)
{
    int count = 0;
    while (_pets[count].get_name() != name)
    {
        if (count + 1 == _pets.size())
        {
            return false;
        }
        count++;
    }
    pet = _pets[count];
    return true;
}

// When this method starts, the _pets[] vector must be sorted in
// non-descending order by _id. If it is not already, then it will be resorted.
bool Pet_Store::find_pet_by_id_bin(long id, Pet& pet)
{
    if(_sort_order != BY_ID)
    {
        _sort_pets_by_id();
    }
    
    int b = (int)_pets.size() - 1;
    for (int a = 0; a <= b;) {
        int mid = (a+b)/2;
        if (_pets[mid].get_id() < id) {
            a = mid + 1;
        }
        else if (_pets[mid].get_id() > id) {
            b = mid - 1;
        }
        else if (_pets[mid].get_id() == id){
            pet = _pets[mid];
            return true;
        }
    }
    return false;
}
// When this method is called, the _pets[] vector must be sorted in // lexicographic non-descending order by _name. If it is not already, // then it will be resorted.
bool Pet_Store::find_pet_by_name_bin(string name, Pet& pet)
{
    if(_sort_order != BY_NAME)
    {
        _sort_pets_by_name();
    }
    
    int b = (int)_pets.size() - 1;
    for (int a = 0; a <= b;) {
        int mid = (a+b)/2;
        if (_pets[mid].get_name() < name) {
            a = mid + 1;
        }
        else if (_pets[mid].get_name() > name) {
            b = mid - 1;
        }
        else if (_pets[mid].get_name() == name){
            pet = _pets[mid];
            return true;
        }
    }
    return false;
}
// Return a string representation of the pets with indexes n1 through n2 // inclusive, exclusive of non-existent indices
// Each pet is on a line by itself.
string Pet_Store::to_string(size_t n1, size_t n2)
{
    string apaaja = "";
    for (int i = (int)n1; i<= (int)n2; i++)
    {
        apaaja += _pets[i].to_string() + "\n";
    }
     return apaaja;
}
