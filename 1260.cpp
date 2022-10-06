#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> arr[1000];
int visited[1000];

void initialize_arr(int n)
{
	for (int i = 0; i < n; i++)
		visited[i] = false;
}

void dfs(int r)
{
	cout << r + 1 << " ";
	visited[r] = true;
	for (int i = 0; i < arr[r].size(); i++)
	{
		if (!visited[arr[r][i]])
			dfs(arr[r][i]);
	}
}

void bfs(int r)
{
	queue<int> q;
	q.push(r);
	visited[r] = true;
	
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x + 1 << " ";
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
	int n, m, r;

	cin >> n >> m >> r;
	r;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
		sort(arr[i].begin(), arr[i].end());
	dfs(r - 1);
	cout << "\n";
	initialize_arr(n);
	bfs(r - 1);
	return (0);
}