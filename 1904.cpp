#include <iostream>
#define MAX 1000001
using namespace std;

int n;
int dp[MAX];

int dfs(int m) {
	if (dp[m])	//저장된 값이 있으면
		return dp[m];

	return dp[m] = (dfs(m - 1) + dfs(m - 2)) % 15746;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	cout << dfs(n);

	return 0;
}