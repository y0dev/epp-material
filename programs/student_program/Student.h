// Student.h

# include <string>

class Student{

    public:

    std::string name;

    int id;

    bool grad;

};

/*
input.txt:

Name1

Name2

Name3

Sample Output:

Please enter the id for student: Name1

101

Please enter 1 for grad and 0 for undergrad for student: Name1

1

Please enter the id for student: Name2

102

Please enter 1 for grad and 0 for undergrad for student: Name2

0

Please enter the id for student: Name3

103

Please enter 1 for grad and 0 for undergrad for student: Name3

1

Name1,101,1

Name3,103,1

Name2,102,0

Please update input.txt with relevant student names prior to execution in your context.
*/
