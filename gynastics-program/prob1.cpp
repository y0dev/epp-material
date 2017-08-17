/*
  EPP Review
  Part 1
  Gymnastics Competition.
*/

#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

// length is the number of elements in the array
int findAverageScore(int scores[], int length ){
  // create variable to store highest and lowest scores
  int highest = 0;
  int lowest = scores[0];
  int total;

  for (int i = 0; i < length; i++) {
    total += scores[i];

    // Check to see if score is greater than the previous highest score
    if (scores[i] >= highest) {
      highest = scores[i];
    }
    // Check to see if score is less than the previous lowest score
    if (scores[i] <= lowest) {
      lowest = scores[i];
    }
  }

  total = total - highest - lowest;
  return total / (length - 2);
}

int main(){
  int N;
  int maxScore = 0;
  int contestant;
  int highestContestant;

  printf("Enter the number of judges: ");
  cin >> N;
  // Array of scores to be stored
  int* scores = new int[N];


  printf("Number of judges entered: %d\n", N);

  while(true){
    puts("Enter contestant number:");
    cin >> contestant;

    if(contestant > 0){

      puts("Enter score: ");
      for (int i = 0; i < N; i++) {
        cin >> scores[i];
      }
      int averageScore = findAverageScore(scores, N);
      if (averageScore >= maxScore) {
        highestContestant = contestant;
        maxScore = averageScore;
      }
      printf("Average score: %d\n", averageScore);

    } else {
      printf("Contestant %d had the highest score.\n", highestContestant);
      break;
    }
  }

  return 0;
}
