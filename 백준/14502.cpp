#include <iostream>
#include <queue>
#define MAX 8
using namespace std;

int n, m, l;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[MAX][MAX];
int graph[MAX][MAX];
int map[MAX][MAX];
queue<pair<int, int>> q;

void init(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = graph[i][j];
			visited[i][j] = 0;
		}
	}
}

void check_virus(void)
{
	init();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 2)
			{
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			//지도가 0이고 방문하지 않았을 때
			if (0 <= ny && ny < n && 0 <= nx && nx < m && !map[ny][nx] && !visited[ny][nx])
			{
				q.push({ny, nx});
				visited[ny][nx] = 1;
				map[ny][nx] = 2;
			}
		}
	}
}

int count_safe(void)
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void make_wall(int wall, int x)
{
	if (wall == 3)
	{
		int cnt;

		check_virus();
		cnt = count_safe();
		if (cnt > l)
			l = cnt;
		return;
	}

	for (int i = x; i < n * m; i++)
	{
		if (graph[i / m][i % m] == 0)
		{
			graph[i / m][i % m] = 1;
			make_wall(wall + 1, i);
			graph[i / m][i % m] = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
	}

	make_wall(0, 0);

	cout << l;
}