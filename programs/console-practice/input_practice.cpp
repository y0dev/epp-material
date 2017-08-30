//
//  input_practice.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/18/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

// This library is used for cin to be used in getline
#include <iostream>
// This lib is used for printf() and scanf()
#include <cstdio>
// This lib is used for getline() and string
#include <string>

using namespace std;


int main() {
    
    printf("What is your name? ");
    
    string name;
    getline(cin,name);
    
    printf("Hello %s! Welcome to Simple.\n",name.c_str());
    
    
    printf("How old are you? ");
    int age;
    scanf("%d",&age);
    
    if (age < 21) {
        printf("I\'m sorry you are too young to take a drink.\n");
    }else{
        printf("Well since you are %d years old you can take a drink!\nSo turn up!\n",age);
    }
    
}