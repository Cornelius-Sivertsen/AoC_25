#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// day3 part 2

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
long int largestJoltage(string batteryBank){
  int bBLen = batteryBank.size();
  long int totalJoltage = 0;
  largest largestFound;
  
  int leftLimit = 0;
  int subStrLen = bBLen - 11;
  
    for (int i = 0; i<= 11; i++){
      largestFound = largestNumber(batteryBank.substr(leftLimit,subStrLen));
      
      totalJoltage += pow(10, (11-i)) * largestFound.digit;
      
      leftLimit = leftLimit + largestFound.index + 1;
      subStrLen = bBLen - leftLimit + 1 - (11-i);


      //      cout << "at iteration " << i << ", found digit: " << largestFound.digit << " at local index: " << largestFound.index << ", new left limit: " <<  leftLimit << " new substr lenght: " << subStrLen << endl;
      
    }

    return totalJoltage;
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

  long int total_max_joltage = 0;

  for (int i = 0; i<batteryBanks.size(); i++){
    largest biggest = largestNumber(batteryBanks[i]);
    int biggest_num = biggest.digit;
    int biggest_index = biggest.index;
    long int joltage = largestJoltage(batteryBanks[i]);
    //    cout << batteryBanks[i]  << " | joltage found: " << joltage <<  endl;
    total_max_joltage += joltage;
  }

  cout << "----------------------------------------------------------------" << endl;
  cout << "total joltage found: " << total_max_joltage << endl << flush;

  return 0;
}

