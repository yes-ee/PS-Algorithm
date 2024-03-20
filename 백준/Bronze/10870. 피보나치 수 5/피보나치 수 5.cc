// dp

#include <iostream>

using namespace std;

int dp[21];
int n;

int main() {
	cin >> n;

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}