#include <iostream>

using namespace std;

int n, f;

int main() {
	cin >> n >> f;

	n /= 100;
	n *= 100;

	for (int i = 0; i < 100; i++) {
		if ((n + i) % f == 0) {
			if (i == 0)
				cout << "00";
			else if (i < 10)
				cout << "0" << i;
			else
				cout << i;
			break;
		}
	}

	return 0;
}