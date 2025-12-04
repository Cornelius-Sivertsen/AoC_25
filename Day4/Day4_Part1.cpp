#include <iostream>
#include <fstream>
#include <vector>

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
}
