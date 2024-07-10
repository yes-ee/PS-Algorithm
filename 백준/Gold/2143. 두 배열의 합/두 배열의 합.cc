#include <iostream>
#include <map>

using namespace std;
using ll=long long;

ll t;
int la, lb;
ll a[1001];
ll b[1001];
map<ll, int> sb;
ll cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	cin >> la;
	for (int i = 0; i < la; i++) {
		cin >> a[i];
	}

	cin >> lb;
	for (int i = 0; i < lb; i++) {
		cin >> b[i];
	}

	ll sum = 0;

	for (int i = 0; i < lb; i++) {
		sum = b[i];
		sb[sum]++;
		for (int j = i + 1; j < lb; j++) {
			sum += b[j];
			sb[sum]++;
		}
	}

	for (int i = 0; i < la; i++) {
		sum = a[i];
		ll idx = t - sum;
		if (sb[idx]) cnt += sb[idx];

		for (int j = i + 1; j < la; j++) {
			sum += a[j];
			ll idx = t - sum;
			if (sb[idx]) cnt += sb[idx];
		}
	}

	cout << cnt;

	return 0;
}