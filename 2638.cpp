#include <iostream>
#include <algorithm>

using namespace std;

int graph[100][100];
int air[100][100];
int visited[100][100];
int pre[100][100];
int n, m, t;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			air[i][j] = 1;
			visited[i][j] = 0;
			pre[i][j] = graph[i][j];
		}
		
	}
}

void dfs(int y, int x) {
	visited[y][x] = 1;
	air[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || graph[ny][nx])
			continue;

		dfs(ny, nx);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >>m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			graph[i][j] = a;
		}
	}

	while (1) {
		int flag = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j]) {
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}

		if (!flag)
			break;


		init();
		dfs(0, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (pre[i][j] == 0)
					continue;
				
				int cnt = 0;

				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if (air[ny][nx] == 0)
						cnt++;
				}

				if (cnt >= 2)
					graph[i][j] = 0;
			}
		}

		t++;
	}

	cout << t;

	return 0;
}