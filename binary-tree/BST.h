// Binary Search Tree Header File


#ifndef BST_H_
#define BST_H_




class BST {
    
    private:
    
    struct Node{
        int value;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    void addLeafPrivate(int,Node*);
    void printInOrderPrivate(Node*);
    Node* returnNodePrivate(int,Node*);
    int findSmallestPrivate(Node*);
    void removeNodePrivate(int,Node*);
    void removeRootMatch();
    void removeMatch(Node* parent,Node* match,bool left);
        
    public:
    
    BST();
    Node* createLeaf(int);
    void addLeaf(int);
    void printInOrder();
    Node* returnNode(int);
    int returnRootValue();
    void printChildren(int);
    int findSmallest();
    void removeNode(int);
};

#endif