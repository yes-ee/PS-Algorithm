#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using ll = long long;
using pll= pair<ll, ll>;

int n;
ll sum;
vector<pll> v;

int main() {
	cin >> n;

	ll x, y;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({x, y});
	}

	v.push_back(v[0]);

	for (int i = 0; i < n; i++) {
		sum += v[i].first * v[i + 1].second;
		sum -= v[i + 1].first * v[i].second;
	}

	long double ans = abs(sum) / 2.0;

	cout.precision(1);
	cout << fixed << ceil(ans * 10) / 10 ;

	return 0;
}