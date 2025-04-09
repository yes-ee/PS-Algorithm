#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;

int n, l, h, sum;
vector<pii> v;
pii mx;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h;
		if (mx.second < h) {
			mx = {l, h};
		}
		v.push_back({l, h});
	}
	sort(v.begin(), v.end());

	int st = v[0].first;
	int curh = v[0].second;

	for (int i = 0; i < n; i++) {
		auto cur = v[i];
		h = v[i].second;
		if (h >= curh) {
			sum += (cur.first - st) * curh;
			curh = h;
			st = cur.first;
		}
		if (mx.first == cur.first) break;
	}
	st = v[n-1].first;
	curh = v[n-1].second;
	for (int i = n-1; i >= 0; i--) {
		auto cur = v[i];
		h = v[i].second;
		if (h >= curh) {
			sum += (st - cur.first) * curh;
			curh = h;
			st = cur.first;
		}
		if (mx.first == cur.first) break;
	}
	sum += mx.second;

	cout << sum;
	return 0;
}