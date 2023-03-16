#include <iostream>
#define MAX 100000
using namespace std;

int n, ans;	//ans : 현재까지 최대값
int dp[MAX];	//i번째 수 포함한 최대
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	ans = dp[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
}