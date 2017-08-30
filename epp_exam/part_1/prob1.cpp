// Devontae Reid
//  palindrome.cpp
//  epp_compiler
//
//  Created by devontae.reid on 8/23/17.
//  Copyright © 2017 devontae.reid. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

/*
 Problem 1. Write a C++ program that takes an array of characters and checks if it is a
 “palindrome” – that is if the array has the same contents whether read from the front or
 the end. If the array is a palindrome, it should print “True”; “False” otherwise.
 
 
 For example, if the input is: ‘r’, ‘a’, ‘c’, ‘e’, ‘c’, ‘a’, ‘r’., the output must be: True
 Another example, if the input is: ‘a’, ‘n’, ‘n’, ‘a’, the output must be: True. (Note that
 palindromes can be odd or even in length.)
 An array can can be checked for a palindrome by comparing its zeroth element with its
 last element, 1st element with second last, and so on.
 Write your program in exactly the following way:
 Write a Boolean function called isPalindrome that takes two parameters:
 • inputArray of chars
 • length of inputArray (int)
 and returns True if inputArray is a palindrome, and False otherwise.
 The function isPalindrome checks the values from the inputArray as described above.
 An example: Calling isPalindrome (inputArray, 7) returns True:
 */

bool isPalindrome(char[],int);

// Create an array of char
// Get user to type in a string
// pass array to palindrome function
// Palindrome
// Loop through char array
// check if letter matches



int main(){
    int length = 7;
    char array[length];// = {'r','a','c','e','c','a','r'};
    
    puts("Enter a word that is 7 characters: ");
    cin >> array;
    
    if (isPalindrome(array, length) == true) {
        puts("This is a palindrome.");
    }else{
        puts("This is not a palindrome.");
    }
}

bool isPalindrome(char array[],int length){
    bool isPalindrome = false;
    for(int i = 0;i < length;i++){
        if (array[i] == array[length-(i+1)]) {
            isPalindrome = true;
        }else {
            isPalindrome = false;
        }
    }
    return isPalindrome;
}
