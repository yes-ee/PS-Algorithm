#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, flag, a, b, ans;
int s, e;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	ans = 2e9;

	s = 0;
	e = n - 1;

	while (s < e) {
		int res = v[s] + v[e];

		if (abs(res) < ans) {
			ans = abs(res);
			a = v[s];
			b = v[e];
			if (res == 0)
				break;
		}
		else if (res > 0)
			e--;
		else
			s++;
	}

	cout << a << " " << b;

	return 0;
}