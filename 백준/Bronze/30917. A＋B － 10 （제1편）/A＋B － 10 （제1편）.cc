#include <iostream>

using namespace std;

int a, b, input;

int main() {
	for (int i = 1; i <= 9; i++) {
		cout << "? A " << i << endl;
		cin >> input;
		if (input == 1) {
			a = i;
			break;
		}
	}

	for (int i = 1; i <= 9; i++) {
		cout << "? B " << i << endl;
		cin >> input;
		if (input == 1) {
			b = i;
			break;
		}
	}

	cout << "! " << a + b << endl;

	return 0;
}