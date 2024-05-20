// sorting

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using pii=pair<int, int>;

int t, n;
int cnt, hi;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	while (t--) {
		vector<pii> v;
		cnt = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}

		sort(v.begin(), v.end());

		hi = n + 1;

		for (int i = 0; i < n; i++) {
			if (v[i].second < hi) {
				cnt++;
				hi = v[i].second;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}