#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

bool visited[600][600];
char graph[600][600];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int n, m, cnt;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] == 'X' || visited[nx][ny])
				continue;
			if (graph[nx][ny] == 'P')
				cnt++;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'I') {
				q.push({i, j});
				visited[i][j] = true;
			}
		}
	}

	bfs();

	if (cnt == 0) {
		cout << "TT";
		return 0;
	}

	cout << cnt;

	return 0;
}