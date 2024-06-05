#include <iostream>

using namespace std;

int arr[10];
int t, n;

int main() {
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 6;
	arr[4] = 4;

	cin >> t;

	while (t--) {
		cin >> n;

		if (n < 5) 
			cout << arr[n] << "\n";
		else 
			cout << "0\n";
	}

	return 0;
}