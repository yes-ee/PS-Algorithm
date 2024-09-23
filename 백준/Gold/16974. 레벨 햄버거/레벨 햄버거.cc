#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x;
ll b[51], p[51];

ll re(ll n, ll x) {
	if (n == 0) return 1;

	if (x == 1) return 0;
	else if (x <= 1 + b[n-1]) return re(n - 1, x - 1);
	else if (x == 2 + b[n - 1]) return p[n - 1] + 1;
	else if (x <= 2 + 2 * b[n - 1]) return re(n - 1, x - 2 - b[n - 1]) + p[n - 1] + 1;
	else return p[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;

	b[0] = 1;
	p[0] = 1;

	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}

	cout << re(n, x);

	return 0;
}