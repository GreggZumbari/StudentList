/* 
 * @author Greggory Hickman
 * @version dev 1.1
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
  char* cmd = new char[7];

  //Student list
  vector<Child> list;
  
  cout << "Hello fellow fleshy mammal. Welcome to my Sunset High School student simulator. Enjoy your stay." << endl;
  cout << "Type in a command to get started." << endl;
  cout << "Commands: " << endl << "ADD" << endl << "PRINT" << endl << "DELETE" << endl;

  cout << "> ";

  cin.getline(cmd, 7);

  //Another way to do what I just did: if (strcmp(input,"ADD")) {
  //Add command - Add a student to the list with specified parameters
  if ((cmd[0] == 'A' || cmd[0] == 'a') &&
      (cmd[1] == 'D' || cmd[1] == 'd') &&
      (cmd[2] == 'D' || cmd[2] == 'd')) {
    char* name = new char[100];
    char* surname = new char[100];
    int id;
    float gpa;
    
    cout << "Student\'s first name: ";
    cin >> name;

    cout << "Student\'s last name: ";
    cin >> surname;

    bool valid = false;
    while (!valid) {
      cout << "Student ID: ";
      cin >> id;
      if (id < 1000000 && id > 0) {
	valid = true;
      }
      else {
	cout << endl << "Invalid input. Please enter a 6-digit number" << endl;
      }
    }

    cout << "Student GPA: ";
    cin >> gpa;

    list.push_back(add(name, surname, id, gpa));
  }
}

Child add(char* name, char* surname, int id, float gpa) {
  Child c;
  c.name = name;
  c.surname = surname;
  c.id = id;
  c.gpa = gpa;
  return c;
}

