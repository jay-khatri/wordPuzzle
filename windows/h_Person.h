#ifndef PERSON_GUARD
#define PERSON_GUARD

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
#include <map>
#include <algorithm>

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
		//constructor just makes eveything zero
		Person(string m_name, string m_pic);
		Person();
		
		//manipulating member functions
		void setName(string i_name);
		string getName();
		void setPic(string i_pic);
		string getPic();
		//logic for adding to the highschores
		void addScore(int gameType, int val);
		//gets the three score vectors
		vector<int> getScores(int gameType);
				
};

void input_people(vector<Person>& input);

void output_people(vector<Person> input);

void output_term(vector<Person>& input);

int topIndex(vector<Person> peeps, int gametype);

//peeps is passed by value so that we dont have to worry about actually messing up the vector of people
string getPlace(vector<Person> peeps, int gametype, int place);

bool isPerson(string name, vector<Person> peeps);

Person &getPerson(string name, vector<Person> &peeps);

#endif
