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

class Person{
	private:
		//basic member functions
		string name;
		string pic;
		vector<int> highThree;
		vector<int> highFour;
		vector<int> highFive;
	public:
		//manipulating member functions	
		void setName(string i_name){name = i_name;}
		string getName(){return name;}
		void setPic(string i_pic){pic = i_pic;}
		string getPic(){return pic;}
		//logic for adding to the highschores
};
