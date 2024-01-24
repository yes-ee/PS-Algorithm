#include <iostream>
#include <vector>
#include <map>

using namespace std;

int t, n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	while (t--) {
		cin >> n;
		map<string, int> m;
		// m.clear();
		ans = 1;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			m[b]++;
		}

		for (auto it : m) {
			ans *= it.second + 1;
		}

		cout << ans - 1 << "\n";
	}

	return 0;
}