#include <iostream>
#define MAX 100
using namespace std;

int n;
long long sum;
int dp[MAX][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for (int i = 1; i <= 9; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[n - 1][i];
	}
	cout << sum % 1000000000;

	return 0;
}