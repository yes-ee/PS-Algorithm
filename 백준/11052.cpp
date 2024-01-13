#include <iostream>
#define MAX 1001
using namespace std;

int dp[MAX];
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> dp[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i / 2; j++)
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
	}

	cout << dp[n];
}