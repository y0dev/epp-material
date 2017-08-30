#include <iostream>
using namespace std;

void passByVal(int val);
void passByRef(int& ref);
void passByPtr(int* ptr);

/*
    MARK: Uncomment below to run this program
 */

int main() {
    
    int x = 7;
    int* xPtr = &x;
    
    printf("x : %i\n",x);
    
    passByVal(x);
    printf("Pass By Value x : %i\n",x);
    
    passByRef(x);
    printf("Pass By Ref x : %i\n",x);
    
    passByPtr(xPtr);
    printf("Pass By Value x : %i\n",x);
    printf("Pass By Ptr x : %i\n",*xPtr);
    
    return 0;
}

void passByVal(int val){
    val = 10;
}

void passByRef(int& ref){
    ref = 20;
}

void passByPtr(int* ptr){
    *ptr = 30;
}