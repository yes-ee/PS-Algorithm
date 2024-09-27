#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n;
ll sum;
vector<ll> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	ll a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	ll cnt = 0;
	ll st = 0;

	// count zero
	for (st = 0; st < n; st++) {
		if (v[st]) break;
	}

	if (st != n)
		sum += v[st];
	else {
		cout << n / 2;
		return 0;
	}

	for (int i = st + 1; i < n; i++) {
		if (v[i]) {
			sum += v[i];
			sum += (cnt + 1) / 2;
			cnt = 0;
		}
		else {
			cnt++;
		}
	}

	sum += (st + cnt + 1) / 2;

	cout << sum;

	return 0;
}