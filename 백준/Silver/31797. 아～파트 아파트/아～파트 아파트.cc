#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int n, m;
vector<pii> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	n--;
	n %= (m*2);

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		v.push_back({a, i});
		v.push_back({b, i});
	}
	sort(v.begin(), v.end());
	cout << v[n].second;
	return 0;
}