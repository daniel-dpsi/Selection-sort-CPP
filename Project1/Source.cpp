/*TXT DOCUMENT FORMAT
SURNAME COUNTRY TIME(IN SECONDS)

EXAMPLE:
Hrobat SLO 158
Paris ITA 157
Mayer AUT 200
Clarey FRA 201
Odermatt SUI 156
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Skier {
private:
	string Surname;
	string Country;
	int Time;
public:
	Skier(const string& surname = "", const string& country = "", int time = 0) : 
		Surname{ surname }, Country{ country }, Time{ time } {} 

	string getSurname() { return Surname; } // Getters for surname, country and time
	string getCountry() { return Country; }
	int getTime() { return Time; }

	void print();
};

void Skier::print() { cout << Surname << " " << Country << " " << Time << endl; } // initializing print function 

vector<Skier*> TimeAscending(vector<Skier*>skier) { // Selection sort
	for (int i = 0; i < skier.size() - 1; i++) {
		for (int j = 0; j < skier.size() - 1 - i; j++) {
			if (skier.at(j) < skier.at(j + 1)) {
				swap(skier.at(j), skier.at(j + 1));
			}
		}
	}
	return skier;
}

int main() {
	vector<Skier*>skier; // initiliazing skier vector

	fstream txt("SMUK.txt", ios::in); // reading data from a provided .txt file

	string Surname;
	string Country;
	int Time;

	while (txt >> Surname >> Country >> Time) {
		skier.push_back(new Skier(Surname,Country,Time)); // parsing info into the vector from the .txt document
	}

	cout << "Output from a .txt document:\n";
	for (auto it : skier) {
		it->print();
	}

	cout << "\n" << "\n";

	cout << "Sorted by time ascending:\n";
	for (auto it : TimeAscending(skier)) {
		it->print();
	}




}
