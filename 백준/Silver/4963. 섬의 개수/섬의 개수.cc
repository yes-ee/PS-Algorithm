#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int graph[50][50];
int visited[50][50];
int w, h, cnt;
int dx[8] = {1, -1, 0, 0, 1,1,-1,-1};
int dy[8] = {0, 0, 1, -1, 1,-1,1,-1};

void bfs(int y, int x) {
	queue<pii> q;
	q.push(make_pair(x, y));
	visited[y][x] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= w || ny >= h || visited[ny][nx] || !graph[ny][nx])
				continue;
			
			q.push(make_pair(nx, ny));
			visited[ny][nx] = 1;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		cin >> w >> h;
		
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++) {
				graph[i][j] = 0;
				visited[i][j] = 0;
			}
		cnt = 0;
		
		for (int i = 0; i< h; i++) {
			for (int j = 0; j < w; j++) {
				int a;
				cin >> a;
				graph[i][j] = a;
			}
		}

		for (int i = 0; i< h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] || !graph[i][j])
					continue;
				
				bfs(i, j);
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}