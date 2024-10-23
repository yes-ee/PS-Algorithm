#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct m {
	int x;
	int y;
};

int n, r, c;
ll dp[501][501];
m mt[501];

void re(int st, int end) {
	for (int i = st; i < end; i++) {
		if (dp[st][i] == 1e9) re(st, i);
		if (dp[i + 1][end] == 1e9) re(i + 1, end);
		dp[st][end] = min(dp[st][end], dp[st][i] + dp[i + 1][end] + mt[st].x * mt[i].y * mt[end].y);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> mt[i].x >> mt[i].y;
		for (int j = 1; j <= n; j++)
			dp[i][j] = 1e9;
		dp[i][i] = 0;
	}


	re(1, n);

	cout << dp[1][n];

	return 0;
}