// dfs

#include <iostream>
#include <vector>

using namespace std;

int graph[16][16];
int n, cnt;

// 1 가로 2 세로 3 대각선
void dfs(int y, int x, int st) {
	if (y == n - 1 && x == n - 1) {
		cnt++;
		return;
	}

	if (st == 1) {
		if (x + 1 < n && graph[y][x + 1] == 0)
			dfs(y, x + 1, 1);
		
		if (y + 1 < n && x + 1 < n && graph[y][x + 1] == 0 && graph[y + 1][x + 1] == 0 && graph[y + 1][x] == 0)
			dfs(y + 1, x + 1, 3);
	} else if (st == 2) {
		if (y + 1 < n && graph[y + 1][x] == 0)
			dfs(y + 1, x, 2);
		
		if (y + 1 < n && x + 1 < n && graph[y][x + 1] == 0 && graph[y + 1][x + 1] == 0 && graph[y + 1][x] == 0)
			dfs(y + 1, x + 1, 3);
	} else {
		if (x + 1 < n && graph[y][x + 1] == 0)
			dfs(y, x + 1, 1);
		
		if (y + 1 < n && graph[y + 1][x] == 0)
			dfs(y + 1, x, 2);
		
		if (y + 1 < n && x + 1 < n && graph[y][x + 1] == 0 && graph[y + 1][x + 1] == 0 && graph[y + 1][x] == 0)
			dfs(y + 1, x + 1, 3);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	dfs(0, 1, 1);

	cout << cnt;

	return 0;
}