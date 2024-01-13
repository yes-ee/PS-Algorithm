#include <iostream>
#define MAX 100000
using namespace std;

int arr[2][MAX];
int dp[2][MAX];
int t, n, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < n; k++)
				cin >> arr[j][k];

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[1][1] + arr[0][0];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

			ans = max(dp[0][n - 1], dp[1][n - 1]);
		cout << ans << "\n";
	}

	return 0;
}