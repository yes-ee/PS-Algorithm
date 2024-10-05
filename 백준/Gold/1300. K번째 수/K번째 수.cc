// binary search

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll k;

bool chk(ll num) {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min(num / i, (ll)n);
	}

	return cnt >= k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	ll st = 0;
	ll ed = min(1e9, pow(n, 2));
	ll mid;

	while (st < ed) {
		mid = (st + ed) / 2;

		if (chk(mid)) {
			ed = mid;
		} else {
			st = mid + 1;
		}
	}

	cout << ed;

	return 0;
}
