#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[50][50];
int arr[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, int m, int n)
{
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	visited[x][y] = true;
	while(!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny])
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main(void)
{
	int t, m, n, k;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < 50; i++)	//ÃÊ±âÈ­
		{
			for (int j = 0; j < 50; j++)
			{
				visited[i][j] = 0;
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] && !visited[i][j])
				{
					bfs(i, j, m, n);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}