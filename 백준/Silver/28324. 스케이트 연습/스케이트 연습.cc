#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n;
vector<ll> v;
ll ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll in;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> in;
		v.push_back(in);
	}
	v.push_back(0);

	for (int i = n; i > 0; i--) {
		int cur = min(v[i], v[i + 1] + 1);
		v[i] = cur;
		ans += cur;
	}

	ans += v[0];

	cout << ans;

	return 0;
}