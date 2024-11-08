// dp
// knapsack

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll w[101];
int c[101];
ll dp[101][10001];
int sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++)
		cin >> c[i];

	for (auto i : c) sum += i;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (c[i] <= j) {
				dp[i][j] = max(dp[i-1][j - c[i]] + w[i], dp[i][j]);
			}
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}

	return 0;
}