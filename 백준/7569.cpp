#include <iostream>
#include <queue>
#include <tuple>
#define MAX 100
using namespace std;

int box[MAX][MAX][MAX];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int m, n, h;
queue<tuple<int, int, int>> q;

void bfs(void)
{
	while (!q.empty())
	{
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (0 <= nx && 0 <= ny && 0 <= nz && nx < m && ny < n && nz < h && box[nz][ny][nx] == 0)
			{
				box[nz][ny][nx] = box[z][y][x] + 1;
				q.push({nz, ny, nx});
			}
		}
	}
}

int main(void)
{
	int result = 0;

	cin >> m >> n >> h;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> box[k][i][j];
				if (box[k][i][j] == 1)
					q.push({k, i, j});
			}
		}
	}

	bfs();

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (box[k][i][j] == 0)
				{
					cout << "-1";
					return (0);
				}
				if (result < box[k][i][j])
					result = box[k][i][j];
			}
		}
	}
	cout << result - 1;
	return (0);
}