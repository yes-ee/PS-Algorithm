#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main() {
	cin >> a >> b >> c >> d;

	int y = b * d;
	int x = a * d + b * c;

	int div = __gcd(y, x);

	if (div != 1) {
		y /= div;
		x /= div;
	}

	cout << x << " " << y;
}