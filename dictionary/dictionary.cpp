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



int main(){
	vector<string> words;
	input_data(words);
	string check = "kjsdhfkjdshf";
	cout << isWord(words, check) << endl;

}
