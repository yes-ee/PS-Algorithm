#include <bits/stdc++.h>

using namespace std;

int s, n, k, r1, r2, c1, c2;
int mid;

void fn(int y, int x, int cnt) {
	if (cnt == s) {
		cout << "0";
		return;
	}

	if (y % n < mid || y % n >= mid + k || x % n < mid || x % n >= mid + k) {
		fn(y / n, x / n, cnt+1);
	} else {
		cout << "1";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

	mid = (n - k) / 2;

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			fn(i, j, 0);
		}
		cout << "\n";
	}

	return 0;
}