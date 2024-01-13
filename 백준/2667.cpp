#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> d;
int visited[26][26];
int house[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int a, int b, int n)
{
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push(make_pair(a, b));
	visited[a][b] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && house[nx][ny] && !visited[nx][ny])
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	return (cnt);
}

int main(void)
{
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &input);
			house[i][j] = input;
		}
	}
	for (int i = 0; i < n; i++)	//탐색 시작 지점 찾기
	{
		for (int j = 0; j < n; j++)
		{
			if (house[i][j] && (!visited[i][j]))	//집이 있고 방문하지 않은경우에서 시작
			{
				int cnt = bfs(i, j, n);
				d.push_back(cnt);
			}
		}
	}
	sort(d.begin(), d.end());
	cout << d.size() << "\n";
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << "\n";
	return (0);
}