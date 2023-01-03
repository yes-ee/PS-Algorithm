#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#define MAX_SIZE 1001
using namespace std;

int n, m;
int graph[MAX_SIZE][MAX_SIZE];
int count[2][MAX_SIZE][MAX_SIZE];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<tuple<int, int, int>> q;

int bfs(void) {
	while (!q.empty()) {
		int wall = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();

		if (y == n && x == m)
			return count[wall][y][x] + 1;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (0 < nx && 0 < ny && nx <= m && ny <= n && count[wall][ny][nx] == 0) {
				if (graph[ny][nx] == 0) {	//안 막혀있음
					q.push({wall, ny, nx});
					count[wall][ny][nx] = count[wall][y][x] + 1;
				}
				else if (wall == 0) {	//막혀있는데, 벽 부신 적 없음 -> 부시기
					q.push({1, ny, nx});
					count[1][ny][nx] = count[wall][y][x] + 1;
				}
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			graph[i][j] = s[j - 1] - '0';
		}
	}

	q.push({0, 1, 1});

	cout << bfs();

	return 0;
}