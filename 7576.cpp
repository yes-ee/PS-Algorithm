#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int box[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m, n;
queue<pair<int, int>> q;

void bfs(void)
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && 0 <= ny && nx < m && ny < n && box[ny][nx] == 0)
			{
				box[ny][nx] = box[y][x] + 1;
				q.push({ny, nx});
			}
		}
	}
}

int main(void)
{
	int result = 0;

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push({i, j});
		}
	}

	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
			{
				cout << "-1";
				return (0);
			}
			if (result < box[i][j])
				result = box[i][j];
		}
	}
	cout << result - 1;
	return (0);
}