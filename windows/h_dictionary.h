#ifndef DI_G
#define DI_G

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <numeric>
#include <string>
#include <sstream>
using namespace std;

void input_data(vector<string>& input){
  ifstream ifs("dictionary.txt");
  while (ifs) {
	if (ifs.eof()) {
      return;
    }
	string word;
    getline(ifs,word);  // use getline to deal with spaces 
	word = word.substr(0, word.length()-1);
	input.push_back(word);
  }
}
bool isWord(vector<string> input, string check){
	for(int i = 0; i<input.size(); i++){
		if(check == input[i]){
			return true;
		}
	}
	return false;
}

#endif
