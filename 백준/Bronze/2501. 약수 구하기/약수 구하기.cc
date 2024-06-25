#include <iostream>

using namespace std;

int n, k, cnt, ans;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cnt++;
		if (cnt == k) {
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}