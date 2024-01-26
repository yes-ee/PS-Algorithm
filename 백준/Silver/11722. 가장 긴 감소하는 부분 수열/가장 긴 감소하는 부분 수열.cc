#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
int arr[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int len = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[j] > len)
				len = dp[j];
		}
		dp[i] = len + 1;
	}

	cout << *max_element(dp, dp + n);
	return 0;
}