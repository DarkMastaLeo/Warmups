#include <iostream>
using namespace std;
#include <string>
string sequence(int n);

int main() {
	sequence(120);
}

string sequence(int n) {

	string seq;
	seq += to_string(n);

	while (n > 1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
			seq += " " + to_string(n);
		}
		else
		{
			n = n * 3 + 1;
			seq += " " + to_string(n);
		}
	}
	cout << seq << endl;
	return seq;//hi
}