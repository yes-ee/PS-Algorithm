#include <iostream>

using namespace std;

int n, m;
int x = 1000;
int y = 1000;

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		x = min(x, a);
		y = min(y, b);
	}

	if (x >= y * 6) {
		cout << y * n;
		return 0;
	}

	cout << (n / 6) * x + (n % 6 * y > x ? x : n % 6 * y);

	return 0;
}