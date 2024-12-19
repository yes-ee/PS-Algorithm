#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
int ans, idx;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		int sum = v[i] * (m - i <= n ? m - i : n);

		if (ans < sum) {
			idx = i;
			ans = sum;
		}
	}

	cout << v[idx] << " " << ans;

	return 0;
}