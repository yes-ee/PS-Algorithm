#include <iostream>
#define MAX 1000
using namespace std;

int dp[MAX][3];
int arr[MAX][3];
int n;
int ans = 987654321;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
		ans = min(ans, dp[n - 1][i]);

	cout << ans;

	return 0;
}