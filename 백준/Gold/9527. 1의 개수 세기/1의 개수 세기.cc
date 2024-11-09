#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b;
ll sum[60];

ll cal(ll num) {
	ll ans = 0;
	int st = 0;
	for (ll i = 54; i > 0; i--) {
		if ((1LL << i) & num) {
			ans += sum[i - 1] + num - (1LL << i) + 1;
			num -= (1LL << i);
		}
	}

	ans += num & 1;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	// 구간 별 1 개수 구하기
	ll n = 1;
	sum[0] = 1;
	for (int i = 1; i <= 55; i++) {
		n *= 2;
		sum[i] = sum[i - 1] * 2 + n;
	}

	cout << cal(b) - cal(a - 1);


	return 0;
}