#include <bits/stdc++.h>
#define MAX 300

using namespace std;

int n, sum;
int arr[MAX];
int dp[MAX];

void solve() {
	for (int i = 3; i < n; i++) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);


	solve();

	cout << dp[n-1];

	return 0;
}
