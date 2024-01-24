#include <iostream>
#include <math.h>

using namespace std;

int l;
string s;
long long ans;
long long dp[51];

int main() {
	cin >> l >> s;

	dp[0] = 1;
	for (int i = 1; i< l; i++) {
		dp[i] = dp[i - 1] * 31 % 1234567891;
	}

	for (int i = 0; i < l; i++) {
		ans += (s[i] - 96) * dp[i] % 1234567891;
	}

	cout << ans % 1234567891;

	return 0;
}