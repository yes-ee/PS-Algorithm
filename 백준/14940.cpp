//bfs

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dis[1000][1000];
int arr[1000][1000];
bool visited[1000][1000];
queue<pair<int, int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (arr[nx][ny] == 0 || visited[nx][ny])
				continue;
			visited[nx][ny] = true;
			dis[nx][ny] = dis[x][y] + 1;
			q.push({nx, ny});
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && dis[i][j] == 0)
				dis[i][j] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				visited[i][j] = true;
				q.push({i, j});
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}