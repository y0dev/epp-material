//
//  array-swap.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/18/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

#include <cstdio>

int main(){
    int* orig_array = new int[5];
    
    printf("Enter 5 numbers to enter into array:\n");
    scanf("%d %d %d %d %d",&orig_array[0],&orig_array[1],&orig_array[2],&orig_array[3],&orig_array[4]);
    
    puts("Before: ");
    for(int i = 0; i < 5;i++){
        printf("| %d",orig_array[i]);
    }
    printf("|\n");
    
    // NOTE: Swap array
    int *swap_array = new int[5];
    for(int i = 0; i < 5;i++){
        swap_array[i] = orig_array[4-i];
    }
    
    puts("After: ");
    for(int i = 0; i < 5;i++){
        printf("| %d",swap_array[i]);
    }
    printf("|\n");
    
    // NOTE: Delete array so that there won't be any memory leaks
    delete orig_array;
    delete swap_array;
}