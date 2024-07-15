// tsp

#include <iostream>
#define INF 987654321

using namespace std;

int dp[16][65536]; // x 에서 출발지점(0) 까지 가는데 걸리는 최소비용
int arr[16][16];
int n;

int dfs(int x, int mask) {
	// visit all
	if (mask == (1 << n) - 1) {
		if (arr[x][0] == 0) return INF; // no route
		else return arr[x][0]; // x -> 0
	}

	if (dp[x][mask]) return dp[x][mask];

	dp[x][mask] = INF;

	for (int i = 0; i < n; i++) {
		// visit || no route
		if (mask & (1 << i) || arr[x][i] == 0) continue;

		dp[x][mask] = min(dp[x][mask], dfs(i, mask | 1 << i) + arr[x][i]);
	}

	return dp[x][mask];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cout << dfs(0, 1);

	return 0;
}