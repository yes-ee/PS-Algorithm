#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int n;
int dp[MAX];
int arr[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max({dp[1], arr[0] + arr[2], arr[1] + arr[2]});

	for (int i = 3; i < n; i++) {
		dp[i] = max({dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]});
	}

	cout << dp[n - 1];

	return 0;
}