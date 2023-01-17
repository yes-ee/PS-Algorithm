#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int n;
int dp[MAX];

void solve(void)
{
	for (int i = 2; i <= n; i++)
	{
		if (i % 6 == 0)
			dp[i] = min({dp[i / 3], dp[i / 2], dp[i - 1]});
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3], dp[i - 1]);
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1]);
		else
			dp[i] = dp[i - 1];
		dp[i]++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	solve();

	cout << dp[n];
}