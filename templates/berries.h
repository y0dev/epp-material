//
//  template-class.hpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/21/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#ifndef BERRIES_H
#define BERRIES_H

#include <stdio.h>
template<typename type>

class berries{
private:
    type info;
public:
    berries(type);
    void setInfo(const type);
    type getInfo();
    void print();
};


#endif /* BERRIES_H */
