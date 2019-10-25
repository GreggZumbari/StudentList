/* 
 * @author Greggory Hickman
 * @version dev 1.2
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

  while (true) {
  
    cout << endl << "Commands: " << endl << "ADD" << endl << "PRINT" << endl << "DELETE" << endl << "ABORT" << endl;

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
      
      cout << endl << "-----" << endl;
      cout << "Student\'s first name: ";
      cin.getline(name, 100);
      
      cout << "Student\'s last name: ";
      cin.getline(surname, 100);
      
      bool valid = false;
      while (!valid) {
	cout << "Student ID: ";
	cin >> id;
	//Only allow up to 6-digit id's because I believe in segregation of numbers
	if (id <= 999999 && id > 0) {
	  valid = true;
	}
	else {
	  cout << endl << "Invalid input. Please enter a 6-digit number" << endl;
	}
      }
      
      cout << "Student GPA: ";
      cin >> gpa;
      
      //Add custom child to the list
      list.push_back(add(name, surname, id, gpa));

    }
      
    //List all current students
    if ((cmd[0] == 'P' || cmd[0] == 'p') &&
	(cmd[1] == 'R' || cmd[1] == 'r') &&
	(cmd[2] == 'I' || cmd[2] == 'i') &&
	(cmd[3] == 'N' || cmd[3] == 'n') &&
	(cmd[4] == 'T' || cmd[4] == 't')) {

      cout << endl << "-----" << endl;

      if (list.size() == 0) {
	cout << "NONE" << endl;
      }
      else {
	for (int i = 0; i < list.size(); i++) {
	  if (i != 0) {
	    cout << endl;
	  }
	  cout << "Student #" << i + 1 << ":" << endl;
	  cout << list[i].name << " " << list[i].surname << endl;
	  cout << "Student ID: " << list[i].id << endl;
	  cout << "Student GPA: " << list[i].gpa << endl;
	}
      }
      cout << "-----" << endl;
      
    }

    //Kill the program
    if ((cmd[0] == 'A' || cmd[0] == 'a') &&
	(cmd[1] == 'B' || cmd[1] == 'b') &&
	(cmd[2] == 'O' || cmd[2] == 'o') &&
	(cmd[3] == 'R' || cmd[3] == 'r') &&
	(cmd[4] == 'T' || cmd[4] == 't')) {
      cout << endl << "Okay, bye. Thank you for donating to the Child Storage Association (CSA)!" << endl;
      return 0;
    }
    
  }
}

//Create a new Student, must return Child
Child add(char* name, char* surname, int id, float gpa) {
  Child c;
  cout.precision(2);
  c.name = name;
  c.surname = surname;
  c.id = id;
  c.gpa = gpa;
  cout << endl << "New Student Added: " << c.name << " " << c.surname << ", " << c.id << ", " << showpoint << c.gpa << endl;
  cout << "Thank you for your donation." << endl;
  cout << "-----" << endl;
  return c;
}

