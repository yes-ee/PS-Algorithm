#include <iostream>

using namespace std;

int n;
int count;
int dp[41];

int fib_recur(int n)
{
	if (n == 1 || n == 2) {
		count++;
		return 1;
	}
	return fib_recur(n - 1) + fib_recur(n - 2);
}

void fib_dp(int n)
{
	//base condition
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		count++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	fib_recur(n);
	cout << count << "\n";

	count = 0;
	fib_dp(n);
	cout << count << "\n";

	return (0);
}