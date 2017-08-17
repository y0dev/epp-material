#ifndef PART_H
#define  PART_H

#include <string>
using namespace std;

class Part{
private:
  string partName;
  string id;
  int quantity;

public:
  void setName(string);
  void setID(string);
  void setQuantity(int);

  string getName();
  string getID();
  int getQuantity();

  string toString();
};

#endif
