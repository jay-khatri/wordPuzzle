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
		Person(string m_name, string m_pic); //assignment constructor
		Person(); //default constructor
		
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

void input_people(vector<Person>& input); //reads people objects from the file "personData.txt"

void output_people(vector<Person> input); //outputs people objects from the file "personData.txt"

void output_term(vector<Person>& input); //for testing output (prints formated person vector)

int topIndex(vector<Person> peeps, int gametype); //supporting function for getPlace (gets the top scoring player's index)

string getPlace(vector<Person> peeps, int gametype, int place); //Gets the player's name and score based on place int

bool isPerson(string name, vector<Person> peeps); //Checks if a person is in the vector peeps

Person &getPerson(string name, vector<Person> &peeps); //returns a reference to a person with name 

#endif
