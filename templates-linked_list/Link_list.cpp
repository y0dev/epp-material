//
//  Link_list.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/22/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#include "Link_list.h"
#include <iostream>
using namespace std;

template <typename t>
Linked_list<t>::Linked_list(){
    this->head = NULL;
}

template <typename t>
void Linked_list<t>::add(t data){
    Node* node = new Node;
    node->info = data;
    node->next = NULL;
    
    // Check if list is empty
    if (head == NULL) {
        head = node;
    }else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

template <typename t>
void Linked_list<t>::addAt(t data,int index){
    Node* curr = new Node;
    curr->info = data;
    curr->next = NULL;
    
    int location = 0;
    
    if (head == NULL) {
        head = curr;
    }else if (index == 0 && head != NULL){
        curr->next = head;
        head = curr;
    }else {
        Node* temp = head;
        while (temp->next != NULL || location == index) {
            temp = temp->next;
            location++;
        }
        
        temp->next = curr;
    }
    
}

template <typename t>
void Linked_list<t>::print(Node* curr){
    if (curr == NULL) {
        cout << "\n";
    }else{
        cout << curr->info << " ";
        print(curr->next);
    }
}

template <typename t>
void Linked_list<t>::print(){
    Node* curr = head;
    print(curr);
}