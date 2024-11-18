#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> d[21];
int dp[1 << 21];

int dfs(int mask, int x) {
	if (x == n + 1) return 0;

	if (dp[mask]) return dp[mask];

	dp[mask] = 1e9;

	for (int i = 1; i <= n; i++) {
		// 이미 한 일이면 패스
		if (mask & (1 << i)) continue;

		dp[mask] = min(dp[mask], dfs(mask | (1 << i), x + 1) + d[x][i]);
	}

	return dp[mask];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i].push_back(0);
		for (int j = 0; j < n; j++) {
			cin >> a;
			d[i].push_back(a);
		}
	}

	cout << dfs(1, 1);

	return 0;
}