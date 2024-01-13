#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int l;
int curX, curY;
int goalX, goalY;
int cnt[300][300];
bool visited[300][300];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(curX, curY));

	if (curX == goalX && curY == goalY)
		return;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx == goalX && ny == goalY)
			{
				cnt[nx][ny] = cnt[a][b] + 1;
				return;
			}
			if (nx >= 0 && nx < l && ny >= 0 && ny < l && !visited[nx][ny])
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				cnt[nx][ny] = cnt[a][b] + 1;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> l;
		cin >> curX >> curY;
		cin >> goalX >> goalY;
		memset(cnt, 0, sizeof(cnt));
		memset(visited, 0, sizeof(visited));
		bfs();
		cout << cnt[goalX][goalY] << "\n";
	}
	return (0);
}