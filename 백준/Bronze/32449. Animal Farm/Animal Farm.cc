#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string nm;
	ll num;
	ll mx_pig = 0;

	vector<ll> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nm >> num;

		if (nm == "pig") {
			mx_pig = max(mx_pig, num);
		} else {
			v.push_back(num);
		}
	}
	
	sum = mx_pig;

	for (auto i : v) {
		if (i < mx_pig) sum += i;
	}

	cout << sum;

	return 0;
}
