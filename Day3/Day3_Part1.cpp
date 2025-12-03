#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// day3 part 1

struct largest{
  int digit;
  int index;
};




// finds largest number (and its index) from a string of numbers
// if multiple, returns the first occurence
largest largestNumber(string numString){

  largest largest_found = {0, 0};
  int currentDigit;

  for (int i = 0; i < numString.size(); i++){
    currentDigit = stoi(numString.substr(i,1));
    if (currentDigit == 9){ //heuristic
      largest_found = {9, i};
      return largest_found;
    }
    else if (currentDigit > largest_found.digit){
      largest_found = {currentDigit, i};
    }
  }
  return largest_found;
}

// finds largest possible joltage in a battery bank
int largestJoltage(string batteryBank){
  int bBLen = batteryBank.size();
  largest firstLargest = largestNumber(batteryBank.substr(0,bBLen-1));
  largest secondLargest = largestNumber(batteryBank.substr(firstLargest.index+1,bBLen-1));

  // cout << "first largest: " << firstLargest.digit << " at index: " << firstLargest.index << endl;
  // cout << "second largest: " << secondLargest.digit << " at index: " << secondLargest.index << endl;
  
  
  return firstLargest.digit*10 + secondLargest.digit;
}

int main(int argc, char *argv[]){
  string inputFileName;
  if (argc == 1){
    inputFileName = "./input";
  }
  else{
    inputFileName = argv[1];
  }

  cout << "You have selected file: " << inputFileName << endl;

  string inputLine;
  ifstream inputFile(inputFileName);
  vector<string> batteryBanks;

  while (getline(inputFile,inputLine)){
    batteryBanks.push_back(inputLine);
  }
  inputFile.close();

  int total_max_joltage = 0;

  for (int i = 0; i<batteryBanks.size(); i++){
    largest biggest = largestNumber(batteryBanks[i]);
    int biggest_num = biggest.digit;
    int biggest_index = biggest.index;
    int joltage = largestJoltage(batteryBanks[i]);
    cout << batteryBanks[i]  << " | joltage found: " << joltage <<  endl;
    total_max_joltage += joltage;
  }

  cout << "----------------------------------------------------------------" << endl;
  cout << "total joltage found: " << total_max_joltage << endl << flush;

  return 0;
}

