#pragma once

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
		Person(string m_name = "", string m_pic = "");
		
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

void output_data(vector<Person> input);

void output_term(vector<Person>& input);

//returns a string given game type and place
//string GUI_out(int gametype, int place, vector<Person> people){
	//place = place -1;
	//vector<int> intcompare;
	//vector<string> strcompare;
	//for(int i = 0; i<people.size();i++){
		//intcompare.push_back(people[i].getScores(gametype)[2]);
	//}
	//for(int i = 0; i<people.size();i++){
		//strcompare.push_back(people[i].getName());
	//}
	//string name = strcompare[place];
	//string inter = ": ";
	//int intwant = intcompare[place];
	//string num = to_string(intwant);
	//string final =  name + inter + num;
	//return final;
//}
//function that return that index of the top scorer in a vecotr

int topIndex(vector<Person> peeps, int gametype);

//peeps is passed by value so that we dont have to worry about actually messing up the vector of people
string getPlace(vector<Person> peeps, int gametype, int place);

bool isPerson(string name, vector<Person> peeps);

Person &getPerson(string name, vector<Person> &peeps);

