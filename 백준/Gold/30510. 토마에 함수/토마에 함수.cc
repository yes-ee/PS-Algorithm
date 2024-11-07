#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum = 2;
int p, q;

ll euler(int n) {
	int ans = n;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0) n /= i;
		}
	}

	if (n > 1) ans -= ans / n;

	return ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> p >> q;

	int mx = q / p;
	for (int i = 2; i <= mx; i++) {
		sum += euler(i);
	}

	cout << sum;

	return 0;
}