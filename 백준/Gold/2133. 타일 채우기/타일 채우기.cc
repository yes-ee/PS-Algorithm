// dp

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll cnt;
ll dp[31];
ll arr[31];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[0] = 0;

	dp[2] = arr[2] = 3;

	for (int i = 4; i <= n; i+= 2)
		arr[i] = 2;

	for (int i = 4; i <= n; i += 2) {
		for (int j = 2; j < i; j += 2) {
			dp[i] += arr[j] * dp[i - j];
		}
		dp[i] += 2;
	}

	cout << dp[n];

	return 0;
}
