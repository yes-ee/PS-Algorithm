#include <iostream>
#define MAX 100
using namespace std;

long long dp[MAX];
int t, a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;

	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = dp[4] = 2;

	for (int i = 5; i < 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	while (t--)
	{
		cin >> a;
		cout << dp[a - 1] << "\n";
	}

	return 0;
}
