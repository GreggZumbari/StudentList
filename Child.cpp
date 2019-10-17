/* 
 * @author Greggory Hickman
 * @version dev 1.0
 */
#include <iostream>
#include <vector>

using namespace std;

//Information storage for a student
struct Child {
  char* name;
  char* surname;
  int id;
  float gpa;
};

//Prototypes
Child add(char* name, char* surname, int id, float gpa);

int main() {
  //Input cstring
  char* cmd;

  //Student list
  vector<Child> list;
  
  cout << "Hello fellow fleshy mammal. Welcome to my Sunset High School student simulator. Enjoy your stay." << endl;
  cout << "Type in a command to get started." << endl;
  cout << "Commands: " << endl << "ADD" << endl << "PRINT" << endl << "DELETE" << endl;

  cout << "> ";
  cin >> cmd;

  //Add command - Add a student to the list with specified parameters
  if ((cmd[0] == 'A' || cmd[0] == 'a') &&
      (cmd[1] == 'D' || cmd[1] == 'd') &&
      (cmd[2] == 'D' || cmd[2] == 'd')) {
    char* name;
    char* surname;
    int id;
    float gpa;

    cout << endl << "Student\'s first name: ";
    cin >> name;

    cout << endl << "Student\'s last name: ";
    cin >> surname;

    cout << endl << "Student ID: ";
    cin >> id;

    cout << endl << "Student GPA: ";
    cin >> gpa;

    add(name, surname, id, gpa);
  }
  
}

Child add(char* name, char* surname, int id, float gpa) {
  
}

