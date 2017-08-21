//
//  templates-practice.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/21/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#include "berries.cpp"

#include <stdio.h>
#include <cstdio>

using namespace std;


int main(){
    berries<int> five( 5 );
    
    five.print();
    
    berries<string> name("Jake from Statefarm");
    
    name.print();
    
    berries<float> five_other( 5.83f );
    
    five_other.print();
    
    puts("\nValues using getInfo() from inside the class:");
    printf("\tValue int : %d\n", five.getInfo());
    printf("\tValue string : %s\n", name.getInfo().c_str());
    printf("\tValue float : %f\n", five_other.getInfo());
    
}