#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;

	if (n >= 1 && n <= 9) {
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= 9; i++) {
		for (int j = 2; j <= 9; j++) {
			if (n == i * j) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}