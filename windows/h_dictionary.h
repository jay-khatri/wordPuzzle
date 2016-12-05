/*Brockway, Khatri, Tiner
Final Project
Last update: 11-25-16
Purpose: function declartions for dictionary functions*/

#ifndef DICT_GUARD
#define DICT_GUARD

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <numeric>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

void input_data(vector<string>& input); //reads a vector of dictionary words for gameplay ease

bool isWord(vector<string> input, string check); //checks if a word is in the vector input

#endif
