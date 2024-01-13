#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int n, k, ans;
queue<pair<int, int>> q;
int visited[MAX];

void bfs(void)
{
	int x, nx;

	x = n;
	while (x <= 100000 && !visited[x])
	{
		q.push({x, 0});
		visited[x] = 1;
		x *= 2;
	}

	while (!q.empty())
	{
		x = q.front().first;
		ans = q.front().second;
		q.pop();

		if (x == k)
			return;

		if (0 <= (x + 1))
		{
			nx = x + 1;
			while (nx <= 100000 && !visited[nx])
			{
				q.push({nx, ans + 1});
				visited[nx] = 1;
				nx *= 2;
			}
		}
		if (0 <= (x - 1))
		{
			nx = x - 1;
			while (nx <= 100000 && !visited[nx])
			{
				q.push({nx, ans + 1});
				visited[nx] = 1;
				nx *= 2;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	bfs();

	cout << ans;

	return 0;
}