#include <iostream>
#include <queue>

using namespace std;
using pii=pair<int, int>;

int n, m;
int arr[501][501];
int visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans, sum, cnt;

void bfs(int y, int x) {
	queue<pii> q;
	q.push({y, x});
	visited[y][x] = 1;
	sum = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		sum++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (!visited[ny][nx] && arr[ny][nx]) {
					visited[ny][nx] = 1;
					q.push({ny, nx});
				}
			}
		}
	}

	ans = max(ans, sum);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;

	for (int i =0 ; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || !arr[i][j])
				continue;

			bfs(i, j);
			cnt++;
		}
	}

	cout << cnt << "\n";
	cout << ans;

	return 0;
}