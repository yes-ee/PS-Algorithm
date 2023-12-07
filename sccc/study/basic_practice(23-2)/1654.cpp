#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, ans;
long long s, e, m;
vector<int> v;

bool fn(int m) {
	int cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / m;
	}

	if (cnt >= n)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	s = 1;
	e = v[k - 1];

	while (s <= e) {
		m = (s + e) / 2;

		if (fn(m)) {
			ans = m;
			s = m + 1;
		}
		else
			e = m - 1;
	}

	cout << ans;
	
	return 0;
}