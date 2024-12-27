#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ull=unsigned long long;

int n;
ll k, ans, sum;
int day[1000100];

ull cal(ll e, ll s) {
	if (s < 0) s = 0;
	ull a = e * (e + 1) / 2;
	ull b = s * (s + 1) / 2;

	return a - b;
}

bool fn(ll num) {
	sum = 0;
	for (int i = 1; i < n; i++) {
		sum += cal(num, num - (day[i + 1] - day[i]));
		if (sum >= k)
			return true;
	}
	sum += cal(num, 0);

	if (sum >= k) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> day[i];
	}

	ll st = 1;
	ll end = 2 * 1e9;

	while (st <= end) {
		ll mid = (st + end) / 2;
		if (fn(mid)) {
			ans = mid;
			end = mid - 1;
		} else {
			st = mid + 1;
		}
	}

	cout << ans;

	return 0;
}