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
		//constructor jsut makes eveything zero
		Person(string m_name = "", string m_pic = ""):name(m_name), pic(m_name) {
			//each vector should start off with three values
			highThree.push_back(0);
			highThree.push_back(0);
			highThree.push_back(0);
			highFour.push_back(0);
			highFour.push_back(0);
			highFour.push_back(0);
			highFive.push_back(0);
			highFive.push_back(0);
			highFive.push_back(0);
		}
		//manipulating member functionsjj
		void setName(string i_name){name = i_name;}
		string getName(){return name;}
		void setPic(string i_pic){pic = i_pic;}
		string getPic(){return pic;}
		//logic for adding to the highschores
		void addScore(int gameType, int val){
			//only add a new score if the score is larger than the first value in the array
			//(which is sorted), then add it and sort it again
			if (gameType == 3){
				highThree.push_back(val);
				//sort the vector
				sort(highThree.begin(), highThree.end());
				//erase the first thing
				highThree.erase(highThree.begin());
				return;
			}
			if (gameType == 4){
				highFour.push_back(val);
				sort(highFour.begin(), highFour.end());
				highFour.erase(highThree.begin());
				return;
			}
			if (gameType == 5){
				highFive.push_back(val);
				sort(highFive.begin(), highFive.end());
				highFive.erase(highThree.begin());
				return;
			}
		}
		//gets the three score vecotors
		vector<int> getScores(int gameType){
			if (gameType == 3){
				return highThree;
			}else if(gameType == 4){
				return highFour;
			}else if(gameType == 5){
				return highFive;
			}else{
				cout << "error in getScores input\n";
				return highFive;
			}
		}
				
};



int main(){
	Person p;
	p.addScore(3, 5);
	p.addScore(3, 4);
	p.addScore(3, 2);
	p.addScore(3, 10);
	p.addScore(3, 16);
	cout << p.getScores(3)[0];
	cout << p.getScores(3)[1];
	cout << p.getScores(3)[2];
	cout << endl;
	p.addScore(4, 5);
	p.addScore(4, 4);
	p.addScore(4, 2);
	p.addScore(4, 10);
	p.addScore(4, 16);
	cout << p.getScores(4)[0];
	cout << p.getScores(4)[1];
	cout << p.getScores(4)[2];
	cout << endl;
	p.addScore(5, 5);
	p.addScore(5, 4);
	p.addScore(5, 2);
	p.addScore(5, 10);
	p.addScore(5, 16);
	cout << p.getScores(5)[0];
	cout << p.getScores(5)[1];
	cout << p.getScores(5)[2];
	cout << endl;
}	
