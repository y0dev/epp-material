//
//  Gymnastic.cpp
//  CPlusPlusWorkStation
//
//  Created by Devontae Reid on 8/22/17.
//  Copyright © 2017 Devontae Reid. All rights reserved.
//

/*
 
 Write a complete C++ program that takes the judges’ scores for a gymnastic event and finds each
 contestant’s score. It should satisfy all the following specifications: it first reads in an integer N that
 gives the number of judges. It then reads in a contestant number followed by N integers which are the
 scores given the contestant by the N judges. The scores should be read into an array, and then the
 program calls a function called findAverageScore that takes N and the array of judges’ scores as
 arguments. The function should find and drop the highest score and the lowest score, and then find
 and return the average of the remaining N-2 scores. The main should then print the contestant
 number and the average score s/he receives for the event to the screen. It will continue to do this
 (read in the contestant number, then the N integers, then print the contestant number and the
 calculated score on a new line) until a negative value is entered for the contestant number. The
 program will then print the contestant number who scored the highest. (You may assume no ties will
 occur.) All input will be from the keyboard and you may also assume that N will never be greater than
 10 and never less than 3. You may format the output in any way as long as it is readable and
 correct, and you may assume all inputs are correct. (JUST WRITE CODE; NO
 DOCUMENTATION REQUIRED except for your NAME and ID at the start of the file!)
 
 
 */


// Read in an integer to store number of judges in N
// Read in the contestant number
// Read in N numbers for the scores into an array
// Call findAverageScore that take in the array and size
// findAverageScore should drop the highest and lowest score then
// then get average score of the left over scores
// Print contestant number
// Print Average score

// Do above while the user doesn't enter a negative number

// After the program will print the contestant with the highest score

#include <iostream>
using namespace std;

double findAverageScore(const double array[],const int length);


int main() {
    
    // Create int to store N and contestant number
    int N,contestNum;
    
    // Create int to store highestContestant and their score
    int highContest = 0,contestScore = 0;
    
    // Read in an integer to store number of judges in N
    cout << "Enter number of judges: \n";
    cin >> N;
    
    while (true){
        
        // Read in the contestant number
        cout << "Enter contestant number: \n";
        cin >> contestNum;
        
        if (contestNum < 0) {
            break;
        }
        
        // Create an array with the size of N
        double scores[N];
        
        // Read in N numbers for the scores into an array
        cout << "Enter the scores: \n";
        for (int i = 0; i < 5; i++) {
            cin >> scores[i];
        }
        
        // Call findAverageScore that take in the array and size
        double averageScore = findAverageScore(scores, N);
        
        // Print contestant number
        // Print Average score
        cout << "Contestant " << contestNum << " Average score : " << averageScore << endl;
        
        // Check to see if contestant has highest score
        if (averageScore > contestScore) {
            contestScore = averageScore;
            highContest = contestNum;
        }
        
        
    }
    
    // After the program will print the contestant with the highest score
    cout << "Contestant " << highContest << "  had the highest score. \n";
    
}

double findAverageScore(const double array[],const int length){
    // findAverageScore should drop the highest and lowest score then
    int highest = 0,lowest = array[0];
    double average;
    
    // Find highest and lowest
    for(int i = 0;i < length;i++){
        if (highest < array[i]) {
            highest = array[i];
        }
        
        if (lowest > array[i]) {
            lowest = array[i];
        }
    }
    
    for (int i = 0; i < length; i++) {
        average += array[i];
    }
    
    // Remove highest and lowest
    // then get average score of the left over scores
    average = average - (highest + lowest);
    average = average/(length-2);
    
    return average;
}