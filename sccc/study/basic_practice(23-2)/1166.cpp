#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
double s, e, m, ans;

bool fn(double m) {
	long long cnt = 1;

	for (int i = 0; i < 3; i++)
		cnt *= (int)(v[i] / m);

	if (cnt >= n)
		return true;
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	s = 0;
	e = *min_element(v.begin(), v.end());

	for(int i = 0; i < 10000; i++) {
		m = (s + e) / 2.0;

		if (fn(m)) {
			ans = m;
			s = m;
		}
		else
			e = m;
	}

	cout << fixed;
	cout.precision(15);
	cout << ans;

	return 0;
}