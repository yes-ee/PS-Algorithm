#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

int main() {
	cin >> n;

	ans = (2 * n + 1) * (2 * n + 1);

	for (int i = n * -1; i <= n; i++) {
		if (i == 0) continue;

		int sum = 1 - i;

		for (int j = n * -1; j <= n; j++) {
			int c = sum - j;
			if (c > n || c < n * -1) continue;
			ans++;
		}
	}

	cout << ans;

	return 0;
}