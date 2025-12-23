#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

// day5 part 1

using namespace std;

bool is_a_digit(char input){
  return input == '0' || input == '1' || input == '2' || input == '3' || input == '4' || input == '5' || input == '6' || input == '7' || input == '8' || input == '9';
}

size_t find_split_index(vector<string> input_data){
  int i;
  for (i = 0;i<input_data.size();i++){
    if (!is_a_digit(input_data[i][0])){
      return i;
    }
  }
  return -1;
}

bool num_in_range(double num, string range){
  string delim = "-";
  string lower_bound_s = range.substr(0, range.find(delim));
  string upper_bound_s = range.substr(range.find(delim)+1);

  double lower_bound = stod(lower_bound_s);
  double upper_bound = stod(upper_bound_s);

  return (num >= lower_bound && num <= upper_bound);
}

bool num_in_ranges(double num, vector<string> ranges){
  for (int i = 0; i<ranges.size(); i++){
    if (num_in_range(num,ranges[i])){
      return true;
    }
  }
  return false;
}

int run_case(vector<string> input_data){

  size_t split_index = find_split_index(input_data);
  vector<string> ids(input_data.begin(), input_data.begin() + split_index);
  vector<string> ingredients(input_data.begin()+split_index+1, input_data.end());

  int fresh_ingredients = 0;

  for (int i = 0; i < ingredients.size(); i++){
    if (num_in_ranges(stod(ingredients[i]),ids)){
      fresh_ingredients++;
    }
  }
  return fresh_ingredients;
}


int main(int argc, char *argv[]){
  string inputFileName;
  bool testing = false;
  if (argc == 1){
    inputFileName = "./input";
  }
  else{
    inputFileName = argv[1];
    testing = true;
  }

  cout << "You have selected file: " << inputFileName << endl;

  string inputLine;
  ifstream inputFile(inputFileName);
  vector<string> input;

  while (getline(inputFile,inputLine)){
    input.push_back(inputLine);
  }
  inputFile.close();

  int output = run_case(input);
  cout << "result: " << output << endl << flush;
  if (testing){
    assert(output == 3);
  }
}
