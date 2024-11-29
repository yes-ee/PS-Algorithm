#include <bits/stdc++.h>

using namespace std;

int t, s;

int main() {
	cin >> t >> s;

	if (t >= 12 && t <= 16 && !s) {
		cout << 320;
	} else {
		cout << 280;
	}

	return 0;
}