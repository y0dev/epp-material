#include "Part.h"


void Part::setName(string name){
  this->partName = name;
}

void Part::setID(string ID){
  this->id = ID;
}
void Part::setQuantity(int quantity){
  this->quantity = quantity;
}

string Part::getName(){
  return this->partName;
}

string Part::getID(){
  return this->id;
}

int Part::getQuantity(){
  return this->quantity;
}

string Part::toString(){
  string s = this->getID() + " " + this->getName() + " " + to_string(this->getQuantity()) + "\n";
  return s;
}
