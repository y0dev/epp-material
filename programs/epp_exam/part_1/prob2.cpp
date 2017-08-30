// Devontae Reid
//  prob2.cpp
//  epp_compiler
//
//  Created by devontae.reid on 8/23/17.
//  Copyright © 2017 devontae.reid. All rights reserved.
//

/*
 Problem 2. Write a complete C++ program to demonstrate “rotating” of a singly linked lists
 of integers – all elements of the linked list get shifted to the left by one position and the first
 node becomes the last. The main component of your program must be a function called
 rotateLeft that takes a pointer (head of the linked list) as input parameter. This function
 should modify the linked list and return a pointer to the modified linked.
 For example, headRotated = rotateLeft (head)
 Input:
 Output (return value):
 You should then write a function called print that takes a pointer to a linked list as a parameter
 */


#include <iostream>
using namespace std;


// Node struct that store data and a Node that points to the next Node
struct Node{
    int data;
    Node* next;
};

// Create LinkedList class
class LinkedList {
private:
    
public:
    // Head pointer of the linked list
    Node* head = NULL;
    
    // Function to add data to linked list
    void add(int data){
        Node* node = new Node;
        node->data = data;
        node->next = NULL;
        
        // Check to see if the list is empty
        if(head != NULL){
            // Assign head point to tempary variable
            Node* curr = head;
            
            // Iterate through list
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
        }else {
            head = node;
        }
    }
    

};


// Prints out the linked list
// Take in a Node pointer as a parameter
void print(Node* ptr){
    if(ptr == NULL){
        puts("");
    }else{
        cout << ptr->data << " ";
        print(ptr->next);
    }
}


// Create a function that rotates the list to the left
Node* rotateLeft(Node* ptr){
    // Create a Node pointer to iterate through
    Node* curr = ptr->next;
    // Create a seperate linked list to store new nodes
    LinkedList tempList;
    
    // Iterate through curr
    while (curr != NULL) {
        // Add data from old nodes to new linked list
        tempList.add(curr->data);
        curr = curr->next;
    }
    // add the last node to the list
    tempList.add(ptr->data);
    return tempList.head;
}



int main(){
    
    // Create a linked list object
    LinkedList list;
    
    // Add data to linked list
    list.add(10);
    list.add(15);
    list.add(30);
    list.add(25);
    list.add(20);
    list.add(35);
    
    // Create a separate node to store linked list
    Node* head = list.head;
    // Print original linked list
    puts("Before:");
    print(head);
    // declare headRotated
    Node* headRotated = NULL;
    // Rotate linked list
    headRotated = rotateLeft(head);
    // Print rotated linked list
    puts("After:");
    print(headRotated);
}

