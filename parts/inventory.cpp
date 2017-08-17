#include <cstdio>
#include <vector>
#include <fstream>
#include "Part.h"

using namespace std;

// Add parts from file if file exist
vector<Part> getPartsFromFile(string);
// Add part to  file
Part addPart();
/* Find part that both take in to paramaters
one paramater is a string which can be the
id number of the part or the name of the part.
Second paramater take a vector that doesn't get
change so should be const
*/
Part findPartWithID(string,const vector<Part>);
Part findPartWithName(string,const vector<Part>);

// Output data to file both take a vector as paramater
void partsArchieve(const vector<Part>);
void quit(const vector<Part>);

/* Main function runs program that has a do while loop to keep
  the program running until you quit the program yourself
*/
int main(){

    // Create variable that stores a char
    char choice;
    vector<Part> parts = getPartsFromFile("textSave.txt");
    bool continue_on = true;

    do {
      // Prompt the user of each choice to choose from
      puts("Enter N to enter a new part.");
      puts("Enter F to find a part.");
      puts("Enter A to archive the the info.");
      puts("Enter Q to quit");


      // // Get user choice using scanf
      // scanf("%c", &choice)

      // Evaluate user choice using a switch statement
      switch (choice) {
        // Add new part
        case 'N':
        case 'n':
          // add parts to vector from the function addPart
          parts.push_back(addPart());
          break;
        case 'F':
        case 'f':
          // While loop is to make sure the user passes a valid choice
          puts("(1) Find by ID:");
          puts("(2) Find by Part Name");
          int num_choice;
          scanf("%d\n",&num_choice );
          // Check situations
          if (num_choice == 1) {
            // If They ask for id
            char id[10];
            puts("Enter ID: ");
            scanf("%s",id);
            Part part = findPartWithID(id,parts);
            if (part.getName() != "") {
                printf("%s\n", part.toString().c_str());
            } else {
                puts("Part wasn\'t found!");
            }
            break;
          } else if (num_choice == 2) {
              char name[100];
              puts("Enter Part Name: ");
              scanf("%s",name);
              Part part = findPartWithName(name,parts);
                if (part.getName() != "") {
                    printf("%s\n", part.toString().c_str());
                } else {
                    puts("Part wasn\'t found!");
                }
              break;
          } else {
              puts("Invalid choice");
          }
          break;
        case 'A':
        case 'a':
          partsArchieve(parts);
          break;
        case 'Q':
        case 'q':
          // Quits program and save file at the same time
          quit(parts);
          continue_on = false;
          break;
      }
    }while (scanf("%c", &choice) != 'Q' || scanf("%c", &choice) != 'q');

}


vector<Part> getPartsFromFile(string file) {
    // file
    ifstream in_file;
    in_file.open(file);
    string id,name;
    int quantity;
    Part part;
    vector<Part> parts;

    // Check if file is open
    if (in_file.is_open()) {
        while (!in_file.eof()) {
            in_file >> id >> name >> quantity;
            part.setID(id);
            part.setName(name);
            part.setQuantity(quantity);
            // Add to vector
            parts.push_back(part);
        }
        in_file.close();

        /*
          Since there is an extra line I had to remove the
          last element in the vector because when I didn't
          it added an extra element to the vector that is not
          need. So I use the pop_back() funtion to remove
          the last element.
        */
        if (parts.size() > 1) {
          parts.pop_back();
        }

    }else {
        puts("File can not open!");
    }
    return parts;
}


Part addPart(){
    int quantity;
    char id[6],partName[100];

    puts("Enter ID: ");
    scanf("%s",id);
    puts("Enter Part Name:");
    scanf("%s",partName);
    puts("Enter Quantity:");
    scanf("%d",&quantity);

    Part part;
    part.setID(id);
    part.setName(partName);
    part.setQuantity(quantity);
    return part;
}

Part findPartWithID(string id,const vector<Part> parts){
    Part part;
    for(Part p: parts){
        if (p.getID() == id) {
            printf("Part found %s",p.getName().c_str());
            part = p;
        }
    }
    return part;
}

Part findPartWithName(string name,const vector<Part> parts){
    Part part;
    for(Part p: parts){
        if (p.getName() == name) {
            printf("Part found %s",p.getName().c_str());
            part = p;
        }
    }
    return part;
}


void partsArchieve(const vector<Part> parts){
  /* Create a output file that erases what
  was there before and update it with new
  data. trunc is the variable that reset
  the file.
  */
  ofstream output("binarySave.dat",ios::out | ios:: trunc);

  for(Part part: parts){
      output << part.toString();
  }
  output.close();
}

void quit(const vector<Part> parts){
  /* Create a output file that erases what
  was there before and update it with new
  data. trunc is the variable that reset
  the file.
  */
    ofstream output("textSave.txt",ios::out | ios:: trunc);

    for(Part part: parts){
      output << part.toString();
    }
    output.close();
    exit(0);
}
