
#ifndef PERSON_G
#define PERSON_G

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
		//constructor jsut makes eveything zero
		Person(string m_name = "", string m_pic = ""):
			name(m_name), 
			pic(m_name),
			//initializing every vector to three instances of 0
			highThree(3,0),
			highFour(3,0),
			highFive(3,0){}
		//manipulating member functions
		void setName(string i_name){name = i_name;}
		string getName(){return name;}
		void setPic(string i_pic){pic = i_pic;}
		string getPic(){return pic;}
		//logic for adding to the highschores
		void addScore(int gameType, int val){
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
		//gets the three score vectors
		vector<int> getScores(int gameType){
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
				
};

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

void output_data(vector<Person> input) {
	ofstream ofs("personData.txt");
	for (int s = 0; s<input.size(); s++) {
		ofs << input[s].getName() << endl << input[s].getPic() << endl;
		for(auto i: input[s].getScores(3)){
			ofs << i << " ";
		}
		ofs << endl;
		for(auto i: input[s].getScores(4)){
			ofs << i << " ";
		}
		ofs << endl;
		for(auto i: input[s].getScores(5)){
			ofs << i << " ";
		}
		ofs << endl;
		if(s != input.size()-1){
			ofs << endl;
		}
	}
}

void output_term(vector<Person>& input) {
	cout << "Vector Size: " << input.size() << endl;
	int count = 0;
	for (auto s : input) {
		cout << s.getName() << ":   " << count << endl << s.getPic() << endl;
		for(auto i: s.getScores(3)){
			cout << i << " ";
		}
		cout << endl;
		for(auto i: s.getScores(4)){
			cout << i << " ";
		}
		cout << endl;
		for(auto i: s.getScores(5)){
			cout << i << " ";
		}
		cout << endl  << endl;
		count++;
	}
}
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

int topIndex(vector<Person> peeps, int gametype){
	int top_index = 0;
	int top_score = 0;
	for(int i = 0; i<peeps.size(); i++){
		int curr = peeps[i].getScores(gametype)[2];
		if (curr  >= top_score){
			top_index = i;
			top_score = curr;
		}
	}
	return top_index;
}
//peeps is passed by value so that we dont have to worry about actually messing up the vector of people
string getPlace(vector<Person> peeps, int gametype, int place){
	vector<Person> topvec;
	vector<string> places;
	//gets the index of the person with the highest score
	for(int i = 0; i<3 & peeps.size() > 0; i++){
		topvec.push_back(peeps[topIndex(peeps, gametype)]);
		peeps.erase(peeps.begin() + topIndex(peeps, gametype));
	}
	for(int i = 0; i<topvec.size(); i++){
		string str_place = to_string(i+1);
		string str_score = to_string(topvec[i].getScores(gametype)[2]);
		string str_name = topvec[i].getName();
		string fin_string = str_place + ": " + str_name + ",  " + str_score;
		places.push_back(fin_string);
	}
	if (place > 0 && place < 4 && gametype > 2 && gametype < 6){
		return places[place-1];
	}else{
		return "You doing something wrong";
	}
}

bool isPerson(string name, vector<Person> peeps){
	for(auto s: peeps){
		if (s.getName().find(name) != string::npos) {
			return true;
		}
	}
	return false;
}

Person &getPerson(string name, vector<Person> &peeps){
	for(int i = 0; i<peeps.size(); i++){
		if (peeps[i].getName().find(name) != string::npos) {
			return peeps[i];
		}
	}
}

#endif
