// bruteforce

#include <iostream>

using namespace std;

int n, k, ans;

int main() {
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		if (i % 10 == k || i / 10 == k) {
			ans += 3600;
			continue;
		}
		for (int j = 0; j < 60; j++) {
			if (j % 10 == k || j / 10 == k) {
				ans += 60;
				continue;
			}
			for (int l = 0; l < 60; l++) {
				if (l % 10 == k || l / 10 == k) {
					ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}