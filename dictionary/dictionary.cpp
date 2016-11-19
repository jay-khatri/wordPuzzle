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
	input.push_back(word);
  }
}
bool isWord(vector<string> input, string check){
	for(auto i: input){
		if(check == i){
			return true;
		}
	}
	return false;
}

int main(){
	vector<string> words;
	input_data(words);
	for(auto i: words){
		cout << i << endl;
	}
	cout << isWord(words, "zunis");
	cout << words.size();

}
