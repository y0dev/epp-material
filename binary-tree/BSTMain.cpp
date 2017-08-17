#include <iostream>
#include "BST.h"
using namespace std;

//int main() {
//    BST tree;
//    int treeItems[10] = {78,10,2,40,-30,38,59,56,67,60};
//    
//    cout << "The tree before!\n";
//    
//    tree.printInOrder();
//    
//    for (int i = 0; i < 10; i++) {
//        tree.addLeaf(treeItems[i]);
//    }
//    
//    cout << "The tree after!\n";
//    
//    tree.printInOrder();
//    
//    cout << endl;
//    
//    int input;
//    
//    do {
//        cout << "Enter a number to be removed from above (-1 to quit): ";
//        
//        cin >> input;
//        if (input == -1) {
//            break;
//        }
//        tree.removeNode(input);
//        
//        cout << "The tree after!\n";
//        
//        tree.printInOrder();
//        
//        cout << endl;
//    } while (input != -1);
//    
//    
//    return 0;
//}