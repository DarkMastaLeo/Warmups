#include <iostream>
#include <time.h>
using namespace std;

void RDA(int Max, int sum);

int main() {
	int Max = 0;
	int sum = 0;
	srand(time(NULL));
	RDA(Max, sum);
}

void RDA(int Max, int sum) {
	for (int i = 0; i < 100; i++) {
		int num = rand() % 1000 + 1;
		sum += num;
		cout << num << endl;
		if (num > Max) {
			Max = num;
		}
	}
	sum /= 100;
	cout << "sum: " << sum << endl;
	cout << "aveage: " << Max << endl;
}