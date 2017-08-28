#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include "Student.h"
using namespace std;

int main()
{
    ifstream myfile ("input.txt");
    ofstream outputfile ("output.txt");
    string line;
    vector<string> v;
    queue<Student> q;
    queue<Student> q1;
    if (myfile.is_open()){

        // Read the file content into a vector of strings
        while ( getline (myfile,line) )
        {
            //cout << line << '\n';
            v.push_back(line);
        }

        // Traverse the vector
        vector<string>::iterator it;
        int id;
        bool grad;
            
        for(it=v.begin() ; it<v.end(); it++ ) {
            cin.clear();
            string name = *it;
            //cout<< name << endl; // prints name
            Student s;
            s.name=name;


            cout<<"Please enter the id for student: " << name << endl;
            cin>>id;

            //cout<<id<<endl;

            s.id=id;

            cout<<"Please enter 1 for grad and 0 for undergrad for student: " << name << endl;
            cin>>grad;


            s.grad=grad;

            // If the student is a grad push him to the grad queue otherwise push him to undergrad queue
            if(grad){
                q.push(s);
            }else{
                q1.push(s);
            }
        }
        myfile.close();

        //merge grad and undergrad queues
        while (!q1.empty())
        {
            Student s= q1.front();
            q.push(s);
            q1.pop();
        }

    // Traverse the merged queue and write the entries to an output file in order. The grad students will be given

    // priority over undergrads while enrolling in the class. File output.txt will contain the prioritized entries

        while (!q.empty()){
            Student s= q.front();
            cout<<s.name<<","<<s.id<<","<<s.grad<<endl;

            outputfile<<s.name<<","<<s.id<<","<<s.grad<<endl;
            q.pop();
        }

        outputfile.close();
    }

return 0;
}

