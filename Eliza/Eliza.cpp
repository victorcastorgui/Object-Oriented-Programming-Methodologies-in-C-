// Student ID: 20399730
//  Eliza.cpp
//  Quest 5
//
//  Created by Victor Castor on 7/22/20.
//  Copyright © 2020 Victor Castor. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <stdlib.h>  

using namespace std;

string rotate_vowels(string& s){
    char lowerVowels[] = {'a','e','i','o','u'};
    char upperVowels[] = {'A','E','I','O','U'};
    string words = "";
    
    for(int i=0; i < (int)s.length(); i++)
    {
        bool apaAja = false;
        for(int n=0; n < 5; n++)
        {
            if(s[i]==lowerVowels[n])
            {
                words+= lowerVowels[(n+1)%5];
                apaAja = true;
            break;
            }
            else if(s[i]==upperVowels[n])
            {
                words += upperVowels[(n+1)%5];
                apaAja = true;
            break;
            }
        }
        if(apaAja == false)
        {
            words += s[i];
        }
    }
    return s = words;
}

string lispify(string s){
    string x= "";
    int i;
    for(i=0;i < (int)s.length(); i++){
        if(s[i]=='s'){
            x+="th";
        }
        else if(s[i]== 'S'){
            x+="Th";
        }
        else{
            x+=s[i];
        }
    }
    return x;
}

void enter()
{
    string s;
    cout << "What?" << endl;
    while(true)
    {
        int v = rand() % 10;
        getline(cin,s);
        if(s == "")
        {
            cout << "What?" << endl;
            continue;
        }
        if(s != "")
        {
            cout << "    " << s << "\n" << endl;
        }
        string eM="!";
        size_t found = s.find(eM);
        if(found!=string::npos)
        {
            cout << "OMG! You don't say!! ";
            cout << s << "!!!!!" << endl;
            continue;
        }
        string a="why";
        size_t foundA = s.find(a);
        string b="what";
        size_t foundB = s.find(b);
        if(foundA != string::npos || foundB != string::npos)
        {
            cout << "I'm sorry, I don't like questions that contain what or why." << endl;
            continue;
        }
        string sF="s";
        size_t found2 = s.find(sF);
        if(found2!=string::npos)
        {
            cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl;
            cout << lispify(s) << "! Sheesh! Now what?" << endl;
            continue;
        }
        string c="Bye";
        size_t foundC = s.find(c);
        string d="Quit";
        size_t foundD = s.find(d);
        if(foundC != string::npos || foundD != string::npos)
        {
            cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break;
        }
        else
        {
            if(v == 8 || v == 9)
            {
                cout << "Huh? Why do you say: " << s << endl;
                continue;
            }
            else
            {
                cout << rotate_vowels(s) << "?" << endl;
                continue;
            }
            break;
        }
    }
}
