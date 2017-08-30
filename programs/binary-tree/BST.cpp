
#include "BST.h"
#include <iostream>

using namespace std;

BST::BST(){
    root = NULL;
}

BST::Node* BST::createLeaf(int value){
    Node* n = new Node;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

void BST::addLeaf(int value){
    addLeafPrivate(value, root);
}

void BST::addLeafPrivate(int value, BST::Node * Ptr){
    if (root == NULL) {
        root = createLeaf(value);
    }else if (value < Ptr->value){
        if (Ptr->left != NULL) {
            addLeafPrivate(value, Ptr->left);
        }else{
            Ptr->left = createLeaf(value);
        }
    }else if (value > Ptr->value){
        if (Ptr->right != NULL) {
            addLeafPrivate(value, Ptr->right);
        }else{
            Ptr->right = createLeaf(value);
        }
    }else{
        cout<< "The value " << value << " has already been added!\n";
    }
    
}

void BST::printInOrder(){
    printInOrderPrivate(root);
}

void BST::printInOrderPrivate(BST::Node * Ptr){
    if (root != NULL) {
        if (Ptr->left != NULL) {
            printInOrderPrivate(Ptr->left);
            
        }
        
        cout << Ptr->value << " ";
        
        if(Ptr->right != NULL){
            printInOrderPrivate(Ptr->right);
        }
    }else{
        cout << "The tree is empty!";
    }
}


BST::Node* BST::returnNode(int value){
   return returnNodePrivate(value, root);
}

BST::Node* BST::returnNodePrivate(int value, BST::Node * Ptr){
    if (Ptr != NULL) {
        if (Ptr->value == value) {
            return Ptr;
        }else {
            if (value < Ptr->value) {
                return returnNodePrivate(value, Ptr->left);
            }else{
                return returnNodePrivate(value, Ptr->right);
            }
            
        }
    }else {
        return NULL;
    }
}


int BST::returnRootValue(){
    if (root != NULL) {
        return root->value;
    }
    else{
        return -10000;
    }
}

void BST::printChildren(int value){
    Node* Ptr = returnNode(value);
    
    if (Ptr != NULL) {
        cout << "Parent Node : " << Ptr->value << endl;
        
        Ptr->left == NULL ?
        cout << "Left Child is equal NULL!\n":
        cout << "Left Child is equal " << Ptr->left->value << endl;
        
        Ptr->right == NULL ?
        cout << "Right Child is equal NULL!\n":
        cout << "Right Child is equal " << Ptr->right->value << endl;
        
    }else {
        cout << "Value " << value <<" is not in the tree!\n";
    }
}


int BST::findSmallest(){
    return findSmallestPrivate(root);
}

int BST::findSmallestPrivate(BST::Node * Ptr){
    if (root != NULL) {
        if (Ptr->left != NULL) {
            return findSmallestPrivate(Ptr->left);
        }else{
            return Ptr->value;
        }
    }else {
        cout << "Tree is empty";
        return  -10000;
    }
}


void BST::removeNode(int value){
    removeNodePrivate(value, root);
}

void BST::removeNodePrivate(int value, BST::Node * parent){
    if (root != NULL) {
        if (value == root->value) {
            
        }else{
            if (value < parent->value && parent->left != NULL) {
                parent->left->value == value ?
                removeMatch(parent,parent->left,true):
                removeNodePrivate(value, parent->left);
            }else if (value > parent->value && parent->right != NULL) {
                parent->left->value == value ?
                removeMatch(parent,parent->right,false):
                removeNodePrivate(value, parent->right);
            }else{
                cout << "The value " << value << " was not found in the tree!\n";
            }
        }
        
    }else {
        cout << "The tree is empty!\n";
    }
}


void BST::removeRootMatch(){
    if (root != NULL) {
        Node* delPtr = root;
        int rootValue = root->value;
        int smallestInRightSubtree;
        
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            delete delPtr;
        }
        
        else if (root->left == NULL && root ->right != NULL){
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            printf("The root node with value %i was deleted. The new root contains value %i.\n",rootValue,root->value);
        }
        
        else if (root->right == NULL && root ->left != NULL){
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            printf("The root node with value %i was deleted. The new root contains value %i.\n",rootValue,root->value);
        }
        
        else {
            smallestInRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestInRightSubtree, root);
            root->value = smallestInRightSubtree;
            printf("The root node with value %i was overwritten with value %i.\n",rootValue,root->value);
        }
    }else{
        cout << "Can not remove root. The tree is empty!\n";
    }
}

void BST::removeMatch(BST::Node *parent, BST::Node *match, bool left){
    if (root != NULL) {
        Node* delPtr;
        int matchValue = match->value;
        int smallestInRightSubtree;
        
        if (match->left == NULL && match->right == NULL) {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            
            printf("The node containing value %i was remove.\n",matchValue);
        }
        
        else if (match->left == NULL && match->right != NULL){
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            printf("The node containing value %i was remove.\n",matchValue);
        }
        
        else if (match->left != NULL && match->right == NULL){
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            printf("The node containing value %i was remove.\n",matchValue);
        }
        
        else{
            smallestInRightSubtree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree, match);
            match->value = smallestInRightSubtree;
        }
    }
}