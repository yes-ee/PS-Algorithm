#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int n;
vector<ll> v;
vector<ll> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
		ans.push_back(a);
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < n; i++) {
		ll a = v[i];
		ll b = ans[i];

		// change need
		if (a != b) {
			ll g = __gcd(a, b);
			a /= g;
			b /= g;
			ll sa = (ll)sqrt((long double)a);
			ll sb = (ll)sqrt((long double)b);
			if (sa * sa != a || sb * sb != b) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";
	return 0;
}