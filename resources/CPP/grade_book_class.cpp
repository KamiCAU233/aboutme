#include <iostream>
#include <string>
using namespace std;

class GradeBook
{
    private:
        string course_name;
        string instructor_name;
    public:
        string getInstructorName()
        {
            return instructor_name;
        }
        void setInstructorName(string new_name)
        {
            instructor_name = new_name;
        }
        void displayMessage()
        {
            cout << "Welcome to the grade book for" << endl << course_name << endl;
            cout << "This course is presented by: " << instructor_name << endl;
        }
    GradeBook(string a, string b): course_name(a), instructor_name(b) {}
};


//StudybarCommentBegin
int main()
{
   // create a GradeBook object; pass a course name and instructor name
   GradeBook gradeBook(
      "CS101 Introduction to C++ Programming", "Professor Smith" );

   // display initial value of instructorName of GradeBook object
   cout << "gradeBook instructor name is: "
      << gradeBook.getInstructorName() << "\n";

   // modify the instructorName using set function
   gradeBook.setInstructorName( "Assistant Professor Bates" );

   // display new value of instructorName
   cout << "new gradeBook instructor name is: "
      << gradeBook.getInstructorName() << "\n";

   // display welcome message and instructor's name
   gradeBook.displayMessage();
   return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
