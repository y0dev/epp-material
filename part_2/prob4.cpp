// Devontae Reid




#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Student struct
struct Student {
    string name;
    int CWID;
    bool isMember;
};

// Methods Declaration

void outputMembers(const vector<Student> members);
bool checkIfMember(int CWID,const vector<Student> members);

int main(int argc, const char * argv[]) {

    // vector of members
    vector<Student> members;
    
    ifstream input;
    input.open("/Users/devontaereid/Documents/git-repos/epp-material/part_2/members.txt");
       int isMember = -1;
    
    if (!input) {
        cerr << "File could not open\n";
    }
    
    while (!input.eof()) {
        Student s;
        input >> s.name >> s.CWID >> isMember;
        //cout << m.CWID << " " << isMember << endl;
        
        if (isMember == 0) {
            s.isMember = false;
        } else if (isMember == 1){
            s.isMember = true;
        }
        members.push_back(s);
    }
    // Pop Last user off because the last line of file is empty
    members.pop_back();
    

    // Boolea to check if user quit
    bool quit = false;
    
    // Show menu until user quit the program
    while (!quit) {
        int id;
        string name;
        char choice;
        
        cout << "S (Sign-up)\n";
        cout << "P (Print)\n";
        cout << "Q (Quit)\n";
        cout << "Enter choice: ";
        
        cin >> choice;
        
        // Create menu
        switch (choice) {
            case 'S':
                // (S) Sign up
                // Ask user for CWID and name
                cout << "Enter name: ";
                cin >> name;
                
                cout << "Enter CWID: ";
                cin >> id;
                
                
                // Check id to see if it has a membership
                // if true
                // Students has a membership
                // else
                // Student is not a member
                if (checkIfMember(id,members)) {
                    cout << "There is a member with that CWID!\n";
                }else {
                    cout << name << " is now a member.\n";
                    Student s;
                    s.name = name;
                    s.CWID = id;
                    members.push_back(s);
                }
                break;
                
            case 'P':
                // (P) Print
                // print out all student member ship with there CWID and name
                for(int i = 0; i < members.size(); ++i){
                    cout << members.at(i).CWID << " " << members.at(i).name << endl;
                }
                break;
                
            case 'Q':
                // (Q) Quit
                // Save students members into a file
                quit = true;
                outputMembers(members);
                

                break;
                
            default:
                cout << "invalid choice\n";
                break;
        }
    }
    
    
}

// Methods Implementation

bool checkIfMember(int CWID,const vector<Student> members){
    // Check if member exist
    bool isMember = false;
    for(int i = 0; i < members.size(); ++i){
        if (members.at(i).CWID == CWID) {
            isMember = true;
            break;
        }
    }
    return isMember;
}


void outputMembers(const vector<Student> members){
    ofstream output;
    output.open("members.txt");
    
    for (int i = 0; i < members.size(); ++i) {
        output << members.at(i).name << " " << members.at(i).CWID << " ";
        if (members.at(i).isMember) {
            output << 1 << endl;
        }else {
            output << 0 << endl;
        }
    }
    
    output.close();
}

