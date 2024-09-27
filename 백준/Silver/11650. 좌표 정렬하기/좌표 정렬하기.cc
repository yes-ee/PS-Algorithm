#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;

int n;
int a, b;
vector<pii> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		v.push_back({a, b});
	}

	sort(v.begin(), v.end());

	for (auto a : v) {
		cout << a.first << " " << a.second << "\n";
	}

	return 0;
}