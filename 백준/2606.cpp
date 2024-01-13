#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[100];	//방문 여부 저장
vector<int> arr[100];
int cnt = 0;

void bfs(int r)
{
	queue<int> q;
	q.push(r);
	visited[r] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < arr[x].size(); i++)
		{
			if (!visited[arr[x][i]])
			{
				q.push(arr[x][i]);
				visited[arr[x][i]] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
		sort(arr[i].begin(), arr[i].end());
	bfs(0);
	cout << cnt - 1;
	return (0);
}