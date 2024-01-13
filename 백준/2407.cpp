#include <bits/stdc++.h>

using namespace std;

int n, m;
long long res = 1;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		res *= (n - i + 1);
		res /= i;
	}

	cout << res;

	return 0;
}