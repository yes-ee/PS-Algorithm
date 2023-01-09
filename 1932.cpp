#include <iostream>
#define MAX 500
using namespace std;

int n, ans;
int dp[MAX][MAX];
int arr[MAX][MAX];

void f(int m) {
	for (int i = 0; i <= m; i++) {
		if (i == 0)
			dp[m][i] = dp[m - 1][i] + arr[m][i];
		else if (i == m)
			dp[m][i] = dp[m - 1][i - 1] + arr[m][i];
		else
			dp[m][i] = max(dp[m - 1][i - 1], dp[m - 1][i]) + arr[m][i];
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++)
		f(i);

	for (int i = 0; i < n; i++)
		ans = max(ans, dp[n - 1][i]);
	cout << ans;

	return 0;
}