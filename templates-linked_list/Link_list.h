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
template <class t>
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



/*
To define a function template, use the keyword template, followed by the template type definition:
template <class T>

We named our template type T, which is a generic data type.
Tap Continue to learn more!



template <class T>
T sum(T a, T b) {
  return a+b;
}

int main () {
    int x=7, y=15;
    cout << sum(x, y) << endl;
}

// Outputs 22





template <class T>
T sum(T a, T b) {
  return a+b;
}

int main () {
  double x=7.15, y=15.54;
  cout << sum(x, y) << endl;
}
// Outputs 22.69



The compiler automatically calls the function for the corresponding type.
When creating a template type parameter, the keyword typename may be used as an alternative to the keyword class: template <typename T>.
In this context, the keywords are identical, but throughout this course, we'll use the keyword class.


*/
