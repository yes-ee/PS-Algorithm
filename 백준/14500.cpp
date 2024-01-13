#include <iostream>
#include <algorithm>
#define MAX 500
using namespace std;

int n, m, sum, ans;
int paper[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int a, int b, int sum, int cnt) {
	if (cnt == 3) {
		ans = max(sum, ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = a + dx[i];
		int ny = b + dy[i];
	
		if (0 <= nx && 0 <= ny && nx < m && ny < n && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			dfs(nx, ny, sum + paper[ny][nx], cnt + 1);
			visited[ny][nx] = 0;
		}
	}
}

void shape(int x, int y) {
		// ㅜ
		if (y + 1 < n && x + 2 < m)
			ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1]);
		// ㅏ
		if (y + 2 < n && x + 1 < m)
				ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 1][x + 1] + paper[y + 2][x]);
		// ㅗ
		if (y - 1 >= 0 && x + 2 < m)
				ans = max(ans, paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y - 1][x + 1]);
		// ㅓ
		if (y + 2 < n && x - 1 >= 0)
				ans = max(ans, paper[y][x] + paper[y + 1][x] + paper[y + 1][x - 1] + paper[y + 2][x]);
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1;
			dfs(j, i, sum + paper[i][j], 0);
			visited[i][j] = 0;
			shape(j, i);
		}
	}

	cout << ans;
}