#include <iostream>
#include <queue>
using namespace std;

int arr[100][100];
int visited[100][100];
int dis[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int n, int m)
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	dis[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && arr[nx][ny])
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
				dis[nx][ny] = dis[x][y] + 1;
			}
		}
	}
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	}
	bfs(n, m);
	cout << dis[n - 1][m - 1];
	return (0);
}