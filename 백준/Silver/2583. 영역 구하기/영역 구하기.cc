#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
int graph[100][100];
vector<int> v;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	graph[y][x] = 1;
	int sum = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n || graph[ny][nx]) continue;

			graph[ny][nx] = 1;
			q.push({ny, nx});
			sum++;
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;

	while (k--) {
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		for (int i = b; i< d; i++) {
			for (int j = a; j < c; j++) {
				graph[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j]) continue;

			v.push_back(bfs(i, j));
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (auto c : v)
		cout << c << " ";
}