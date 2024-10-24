#include <iostream>

using namespace std;

int n;
int len = 2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		len = len * 2 - 1;
	}

	cout << len * len;

	return 0;
}