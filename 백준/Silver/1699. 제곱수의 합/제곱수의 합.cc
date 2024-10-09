#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int nm = sqrt(i);
		int cnt = 1e9;
		for (int j = nm; j >= 1; j--) {
			cnt = min(cnt, dp[i - j * j] + 1);
		}
		dp[i] = cnt;
	}

	cout << dp[n];

	return 0;
}
