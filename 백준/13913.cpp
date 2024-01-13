#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 100001
using namespace std;

int visited[MAX];	//방문 시 이전 위치 저장
stack<int> path;
queue<pair<int, int>> q;	//현재 위치, 도착 시간 저장
int n, k;

int bfs(void)
{
	q.push({n, 1});
	visited[n] = -1;

	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		if (x == k)
		{
			cout << t - 1 << "\n";
			return t - 1;
		}

		if (0 <= x - 1 && x - 1 <= 100000 && visited[x - 1] == -2)
		{
			int nx = x - 1;
			q.push({nx, t + 1});
			visited[nx] = x;
		}
		if (0 <= x + 1 && x + 1 <= 100000 && visited[x + 1] == -2)
		{
			int nx = x + 1;
			q.push({nx, t + 1});
			visited[nx] = x;
		}
		if (0 <= x * 2 && x * 2 <= 100000 && visited[x * 2] == -2)
		{
			int nx = x * 2;
			q.push({nx, t + 1});
			visited[nx] = x;
		}
	}
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, idx;
	cin >> n >> k;

	for (int i = 0; i < MAX; i++)
		visited[i] = -2;

		t = bfs();

	idx = k;
	path.push(k);

	for (int i = 0; i < t; i++)
	{
		path.push(visited[idx]);
		idx = visited[idx];
	}

	for (int i = 0; i <= t; i++)
	{
		cout << path.top() << " ";
		path.pop();
	}

		return 0;
}
