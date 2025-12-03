#include <iostream>
#include <fstream>
#include <vector>

// day1 part2

using namespace std;

enum Direction
  {
    LEFT,
    RIGHT
  };

class Dial {
  int calculated_password; //counts times the dial lands on 0 or moves past 0
  void moveLeft(int); // Moves the dial to the left, wrapping properly at 0
  void moveRight(int); // Moves the dial to the right, wrapping properly at 99
  Direction decodeDirection(string); // Figures out direction to move from an instruction string
  int decodeSteps(string); // Figures out the number of steps to move from an instruction string
public:
  int position;
  void moveDial(string); // Moves the dial in the correct direction and number of steps, and updates the current position
  int getPassword(void);
  Dial(int basePosition = 50, int basePassword = 0){
    position = basePosition;
    calculated_password = basePassword;
  }
  
};

void Dial::moveLeft(int steps){
  int current = this -> position;
  int turn = steps;

  bool was_0 = (current == 0);

  while (current - turn < 0){
    turn -= 100;
    if (not was_0){
      this -> calculated_password += 1;
    }
    was_0 = false;
  }

  this -> position = (current - turn);
  if (this -> position == 0){
    this -> calculated_password += 1;
  }
  
}

void Dial::moveRight(int steps){
  
  int current = this -> position;
  int turn = steps;

  while(current + turn >= 100){
    turn -= 100;
    this -> calculated_password +=1;
  }
  
  this -> position = (this -> position + turn);
}

Direction Dial::decodeDirection(string instruction){
  string L = "L";
  string input = instruction.substr(0,1);
  if (input == L){return LEFT;}
  else {return RIGHT;}
}

int Dial::decodeSteps(string instruction){
  int step_str_length = instruction.size() - 1;
  return stoi(instruction.substr(1,step_str_length));
}

void Dial::moveDial(string instruction){
  int steps = decodeSteps(instruction);
   Direction dir = decodeDirection(instruction);
  if (dir == LEFT){
     moveLeft(steps);
  }
  else {
     moveRight(steps);
  }

  // if (this -> position == 0){
  //   this -> calculated_password += 1;
  // }
 }

int Dial::getPassword(void){
  return this -> calculated_password;
}


int main(void) {
  cout << "Running program" << endl << flush;

  string line;
  ifstream input_file("./input");
  vector<string> operations;
  
  while (getline(input_file,line)){
    operations.push_back(line);
  }
  input_file.close();

  
  Dial myDial;

  cout << myDial.position << endl;

  for (int i = 0; i < operations.size(); i++){
    cout << "-------------------------" << endl;
    myDial.moveDial(operations[i]);
    cout << "position after rotation: " << myDial.position << endl;
    cout << "current password: " << myDial.getPassword() << endl;
  }

  cout << "calculated password: " << myDial.getPassword() << endl;
  cout << "final position: " << myDial.position << endl;
  
  return 0;
}

