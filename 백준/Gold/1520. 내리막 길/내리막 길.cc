// dfs + dp

#include <iostream>

using namespace std;

int m, n, cnt;
int graph[500][500];
int dp[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int y, int x) {
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || graph[y][x] <= graph[ny][nx])
			continue;

		dp[y][x] += dfs(ny, nx);
	}

	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	dp[m-1][n-1] = 1;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	dfs(0, 0);

	cout << dp[0][0];

	return 0;
}
