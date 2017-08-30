// Devontae Reid
//  prob3.cpp
//  epp_compiler
//
//  Created by devontae.reid on 8/23/17.
//  Copyright © 2017 devontae.reid. All rights reserved.
//


#include <iostream>
#include <cstdio>

using namespace std;


// Point the last .next to head
struct Node{
    int data;
    Node* next;
};


class LinkedList {
private:
    
public:
    Node* head = NULL;
    
    void add(int data){
        Node* node = new Node;
        node->data = data;
        node->next = NULL;
        
        if(head != NULL){
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
        }else {
            head = node;
        }
    }
    
    
};

void print(Node* ptr){
    if(ptr == NULL){
        puts("");
    }else{
        cout << ptr->data << " ";
        print(ptr->next);
    }
}

int product(Node* ptr){
    if(ptr == NULL){
        return 1;
    }else {
        return ptr->data * product(ptr->next);
    }
}


int main(){
    LinkedList list;
    list.add(15);
    list.add(30);
    list.add(25);
    list.add(20);
    list.add(35);
    list.add(10);
    
    Node* head = list.head;
    print(head);
    
    printf("Product: %d\n",product(head));
}


