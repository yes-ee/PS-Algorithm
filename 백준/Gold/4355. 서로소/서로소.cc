#include <bits/stdc++.h>

using namespace std;

int n;

void phi(int n) {
	int ans = n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
		ans -= ans / n;
	
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> n;
		if (!n) break;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
	
		phi(n);
	}
	
	return 0;
}