#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int dp[10001];
int coin[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= k; i++) {
		dp[i] = 1e9;
	}

	for (int i = 1; i <=k; i++) {
		int cnt = 1e9;
		for (int j = 1; j <= n; j++) {
			if (coin[j] > i) continue;

			cnt = min(cnt, 1 + dp[i - coin[j]]);
		}
		dp[i] = cnt;
	}

	if (dp[k] == 1e9) cout << -1;
	else cout << dp[k];

	return 0;
}
