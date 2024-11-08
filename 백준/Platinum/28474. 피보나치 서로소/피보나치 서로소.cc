#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int ans;
int euler(int n) {
	int cnt = n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) cnt -= cnt / i;
		while (n % i == 0) {
			n /= i;
		}
	}

	if (n > 1) {
		cnt -= cnt / n;
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		if (n == 1 || n == 2) {
			cout << n - 1 << "\n";
			continue;
		}

		ans = n;

		ans = euler(n);
		if (n % 2 == 0) ans += euler(n/2);

		cout << ans << "\n";
	}

	return 0;
}