#include <iostream>
#define MAX 1e9

using namespace std;

int arr[1000][3];
int dp[1000][3];
int n, ans = 1e9;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			if (k != i) {
				dp[0][i] = MAX;
			} else {
				dp[0][i] = arr[0][i];
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i][j];
			}
		}

		for (int i = 0; i < 3; i++) {
			if (i == k) continue;
			ans = min(ans, dp[n - 1][i]);
		}
	}

	cout << ans;
	return 0;
}