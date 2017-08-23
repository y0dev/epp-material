//
//  Link_list.hpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/22/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#ifndef Link_list_h
#define Link_list_h

// Create a template that is use for this class
template <typename t>
class Linked_list {
private:
    
    /*
     Couldn't create a class of node that can take in any data type
     So created a struct instead
     
     */
    struct Node {
        t info;
        Node* next;
    };
    
    Node* head;
    
    void print(Node*);
    
public:
    Linked_list();
    void add(t);
    void addAt(t,int);
    
    void print();
};

#endif /* Link_list_hpp */
