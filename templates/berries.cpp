//
//  template-class.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/21/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#include "berries.h"
#include <iostream>

using namespace std;

template<typename type>
berries<type>::berries(type info){
    this->info = info;
}

template <typename type>
void berries<type>::setInfo(const type info){
    this->info = info;
}

template<typename type>
type berries<type>::getInfo(){
    return this->info;
}

template<typename type>
void berries<type>::print(){
    cout << this->info << endl;
}