// dp

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = max(dp[i - 1][j - 1], a) + arr[i][j];
		}
	}

	cout << dp[n][m];

	return 0;
}
