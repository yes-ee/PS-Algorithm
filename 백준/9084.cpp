#include <iostream>

using namespace std;

int t;
int dp[10001];	//금액 별 가짓수
int coin[20];	//동전의 금액 배열

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> coin[j];

		cin >> m;
		dp[0] = {1};
		for (int j = 1; j <= m; j++)
			dp[j] = 0;

		for (int j = 0; j < n; j++)
		{
			for (int k = coin[j]; k <= m; k++)
				dp[k] += dp[k - coin[j]];
		}
		cout << dp[m] << "\n";
	}
	return (0);
}