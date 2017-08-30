//
//  prob2_template.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/22/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#include <cstdio>
#include "Link_list.cpp"

// Create a link list class that can store any data type


int main() {
    
    // Int List
    Linked_list<int> intList;
    
    intList.add(3);
    intList.add(3);
    intList.add(3);
    
    // String List
    Linked_list<string> stringList;
    stringList.add("Devontae");
    stringList.add("Izzy");
    
    // Character List
    Linked_list<char> charList;
    charList.add('A');
    charList.add('B');
    charList.add('C');
    charList.add('D');
    
    // Double List
    Linked_list<double> doubleList;
    doubleList.add(3.8);
    doubleList.add(4.3);
    doubleList.add(8.1);
    
    // Float List
    Linked_list<float> floatList;
    floatList.add(3.842);
    floatList.add(4.321);
    floatList.add(8.113);
    
    
    intList.addAt(1, 0);
    intList.addAt(4, 9);
    
    stringList.addAt("Hector", 0);
    stringList.addAt("Mary", 7);
    
    charList.addAt('a', 0);
    charList.addAt('Z', 26);
    
    doubleList.addAt(42.21, 0);
    doubleList.addAt(6.7, 8);
    
    floatList.addAt(63.2189, 0);
    floatList.addAt(792.112, 7);
    
    // Print list
    intList.print();
    stringList.print();
    charList.print();
    doubleList.print();
    floatList.print();
}