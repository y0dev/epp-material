#include <iostream>
using namespace std;

int factorial(int num){
  if(num == 1){
    return 1;
  }else {
    return factorial(num-1) * num;
  }
}

int main() {

  cout << factorial(5) << endl;

  return 0;

}



//Outputs 120
