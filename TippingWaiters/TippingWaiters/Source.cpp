#include <iostream>
using namespace std;

int possible_payments(int bill, int cash);

int main() {
	possible_payments(4, 100);
	cout << endl;
	possible_payments(1234567, 12345678);
	cout << endl;
	possible_payments(220, 239);
	cout << endl;
}

int possible_payments(int bill, int cash) {
	int min;
	int max;
	int payments = 0;

	min = bill + (bill + 18) / 19; //5%
	max = bill + bill / 9; //10%

	cout << min << endl;
	cout << max << endl;

	if (cash <= max) {
		max = cash;
	}

	while (min % 5 != 0) {
		min++;
		cout << "+1" << endl;
		cout << min << endl;
	}
	while (max % 5 != 0) {
		max--;
		cout << "-1" << endl;
		cout << max << endl;
	}
	cout << "possible payments:" << endl;
	cout << min << endl;
	cout << max << endl;

	if (max >= min) {
		payments = 1 + (max - min) / 5;
	}

	cout << "There are " << payments << " possible payments" << endl;
	return payments;
}

