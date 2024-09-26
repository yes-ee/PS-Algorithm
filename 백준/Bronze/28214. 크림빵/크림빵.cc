#include <bits/stdc++.h>

using namespace std;

int n, k, p, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> p;

	int a;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < k; j++) {
			cin >> a;
			if (a == 0) {
				cnt++;
			}
		}
		if (cnt < p) ans++;
	}

	cout << ans;

	return 0;
}