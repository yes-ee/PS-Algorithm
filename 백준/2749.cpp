#include <iostream>

using namespace std;

long long n;
int dp[1500000];

int main() {
	cin >> n;

	dp[1] = 1;

	for (int i = 2; i < 1500000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
	}

	cout << dp[n % 1500000];

	return 0;
}