/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: function defintions for the dictionary*/

#include "h_dictionary.h"

void input_data(vector<string>& input){
  ifstream ifs("dictionary.txt");
  while (ifs) {
	if (ifs.eof()) {
      return;
    }
	string word;
    getline(ifs,word);  // use getline to deal with spaces 
	//word = word.substr(0, word.length()-1);
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