/*Brockway, Khatiri, Tiner
Final Project
Last update: 11-14-16
Purpose: function and class defintions for the person class*/

#include "h_Person.h"

Person::Person(string m_name = "", string m_pic = ""):
	name(m_name), 
	pic(m_name),
	//initializing every vector to three instances of 0
	highThree(3,0),
	highFour(3,0),
	highFive(3,0){}

void Person::setName(string i_name){
	name = i_name;
}

string Person::getName(){ return name;}

void Person::setPic(string i_pic){ pic = i_pic;}

string Person::getPic(){ return pic;}

void Person::addScore(int gameType, int val){
	//only add a new score if the score is larger than the first value in the array
	//(which is sorted), then add it and sort it again
	if (gameType == 3){
		//name = "yo";
		highThree.push_back(val);
		//sort the vector
		sort(highThree.begin(), highThree.end());
		//erase the first thing
		highThree.erase(highThree.begin());
	}
	if (gameType == 4){
		highFour.push_back(val);
		sort(highFour.begin(), highFour.end());
		highFour.erase(highFour.begin());
	//cout << val << endl;
	}
	if (gameType == 5){
		highFive.push_back(val);
		sort(highFive.begin(), highFive.end());
		highFive.erase(highFive.begin());
	//cout << val << endl;
	}
}

vector<int> Person::getScores(int gameType){
	if (gameType == 3){
		return highThree;
	}else if(gameType == 4){
		return highFour;
	}else if(gameType == 5){
		return highFive;
	}else{
		cout << "error in getScores input\n";
		vector<int> bad;
		return bad;
	}
}

void input_people(vector<Person>& input){
  ifstream ifs("personData.txt");
  while (ifs) {
	if (ifs.eof()) {
	cout << "once";
	  return;
	}
	Person n;	
    string name;
    string picture;
	string check;
	//string check;
	int t1;int t2;int t3;
	int r1;int r2;int r3;
	int f1;int f2;int f3;
    getline(ifs,name);  // use getline to deal with spaces 
	cout << name << endl;
    getline(ifs,picture); // use getline to deal with spaces
	ifs >> t1 >> t2 >> t3;
	ifs >> r1 >> r2 >> r3;
	ifs >> f1 >> f2 >> f3;
	ifs.ignore();
	ifs.ignore();
    getline(ifs,check); // use getline to deal with spaces
	//getline(ifs,check); // use getline to deal with spaces
	n.setName(name);
	n.setPic(picture);
	n.addScore(3, t1);n.addScore(3, t2);n.addScore(3, t3);
	n.addScore(4, r1);n.addScore(4, r2);n.addScore(4, r3);
	n.addScore(5, f1);n.addScore(5, f2);n.addScore(5, f3);
	input.push_back(n);
	if(check != ""){
		return;
	}
  }
}
	
