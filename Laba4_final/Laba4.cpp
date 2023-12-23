#include <iostream>
#include "mnk.h"

using namespace std;

int main()
{
	float x[] = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 };
	float y[] = { 0.957, 0.969, 0.976, 0.978, 0.975, 0.968, 0.954, 0.939, 0.918, 0.894 };

	float* c = MNK(x, y, 10, 2);

	cout << "Coefficients: ";
	for (int i = 0; i <= 2; i++) {
		cout << c[i] << " ";
	}
	cout << endl;

	cout << "Deviation: " << CalcOtkl(x, y, 10, c, 3) << endl;

	return 0;
}
