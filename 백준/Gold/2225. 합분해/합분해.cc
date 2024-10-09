#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int dp[201][201];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 0; i <= k; i++) {
		dp[i][0] = 1;
	}

	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= 1000000000;
			}
		}
	}

	cout << dp[k][n];

	return 0;
}
