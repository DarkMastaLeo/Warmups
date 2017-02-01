#include <iostream>
using namespace std;
#include <string>
int main() {
	string input;


	while (!(input == "no" || input == "yes")) {
		cout << "Are the New England Patriots your favorite team?" << endl;
		cin >> input;
		if (input == "yes")
			cout << "NOOOOOOOOOOOOOOOOO,  useless" << endl;
		else if (input == "no")
			cout << "Okay then..." << endl;
		else
			cout << "invalid input" << endl;
	}
}