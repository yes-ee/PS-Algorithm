#include <iostream>

using namespace std;

int dx[3] = {1, -1, 0};
int dy[3] = {1, 1, -1};
int n, x, y, ans;
int visited[100][100];

void dfs(int x, int y, int cnt, int pre, int dir) {
	if (cnt == n) return;

	for (int i = 0; i < 3; i++) {
		if (i == pre) continue;

		int ny = y + dy[i] * dir;
		int nx = x + dx[i] * dir;

		if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100) continue;

		if (visited[ny][nx]) {
			if (cnt == (n - 1)) {
				ans++;
			}
			continue;
		}

		visited[ny][nx] = 1;
		dfs(nx, ny, cnt + 1, i, dir * -1);
		visited[ny][nx] = 0;
	}
}

int main() {
	cin >> n;

	x = 50;
	y = 50;
	visited[y][x] = 1;
	visited[y + 1][x] = 1;

	dfs(x, y, 0, 2, -1);

	cout << ans;

	return 0;
}