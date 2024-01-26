#include <iostream>

using namespace std;

int t, a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int ans = 1;
		cin >> a >> b;

		for (int i = 0; i < b; i++) {
			ans *= a;
			ans %= 10;
		}
		if (ans == 0)
			ans = 10;
		cout << ans << "\n";
	}

	return 0;
}