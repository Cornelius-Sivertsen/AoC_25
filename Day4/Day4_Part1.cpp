#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

// day4 part 1

using namespace std;

enum position_state_t{
  MIDDLE,
  TOP_EDGE,
  BOT_EDGE,
  LEFT_EDGE,
  RIGHT_EDGE,
  TL_CORNER,
  TR_CORNER,
  BL_CORNER,
  BR_CORNER
};

position_state_t find_state(int row, int column, int max_rows, int max_columns){

  if (row == 0 && column == 0){
    return TL_CORNER;
  }
  else if (row == 0 && column == max_columns-1){
    return TR_CORNER;
  }
  else if (row == 0){
    return TOP_EDGE;
  }
  else if (row == max_rows-1 && column == max_columns-1){
    return BR_CORNER;
  }
  else if (column == max_columns-1){
    return RIGHT_EDGE;
  }
  else if (row == max_rows-1 && column == 0){
    return BL_CORNER;
  }
  else if (row == max_rows-1){
    return BOT_EDGE;
  }
  else if (column == 0){
    return LEFT_EDGE;
  }
  else{
    return MIDDLE;
  }
}

int count_around(size_t row, size_t column, vector<string> table){
  position_state_t state = find_state(row,column,table.size(),table[0].size());

  size_t row_min, row_max, col_min, col_max;

  switch(state){
  case MIDDLE:
    row_min = row - 1;
    row_max = row + 1;
    col_min = column - 1;
    col_max = column + 1;
    break;
  case TOP_EDGE:
    row_min = row;
    row_max = row + 1;
    col_min = column - 1;
    col_max = column + 1;
    break;
  case BOT_EDGE:
    row_min = row - 1;
    row_max = row;
    col_min = column - 1;
    col_max = column + 1;
    break;
  case LEFT_EDGE:
    row_min = row - 1;
    row_max = row + 1;
    col_min = column;
    col_max = column + 1;
    break;
  case RIGHT_EDGE:
    row_min = row - 1;
    row_max = row + 1;
    col_min = column - 1;
    col_max = column;
    break;
  case TL_CORNER:
    row_min = row;
    row_max = row + 1;
    col_min = column;
    col_max = column + 1;
    break;
  case TR_CORNER:
    row_min = row;
    row_max = row + 1;
    col_min = column - 1;
    col_max = column;
    break;
  case BL_CORNER:
    row_min = row - 1;
    row_max = row;
    col_min = column;
    col_max = column + 1;
    break;
  case BR_CORNER:
    row_min = row - 1;
    row_max = row;
    col_min = column - 1;
    col_max = column;
    break;
  }

  int count = 0;

  int i;
  int j;

  for(i = row_min; i<=row_max; i++){
    for(j = col_min; j<=col_max;j++){
      if (table[i][j] == '@'){
	if (!(i == row && j == column)){
	  count++;
	}
      }
    }
  }
  return count;
}

int run_case(vector<string> input_data){
  int free_rolls = 0;

  int i,j;
  int tmp;
  for(i=0;i<input_data.size();i++){
    for(j=0;j<input_data[0].size();j++){
      if (input_data[i][j] == '@'){
	tmp = count_around(i,j,input_data);
	if (count_around(i,j,input_data) < 4){
	  free_rolls++;
	}
      }
    }
  }
  return free_rolls;
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
    assert(output == 13);
  }
}
