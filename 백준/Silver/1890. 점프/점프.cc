#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int n;
int arr[101][101];
ll dp[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int mv = arr[i][j];

			if (mv == 0) continue;

			if (i + mv < n) dp[i + mv][j] += dp[i][j];
			if (j + mv < n) dp[i][j + mv] += dp[i][j];
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}