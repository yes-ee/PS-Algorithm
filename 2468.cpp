#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int n;
int cnt[MAX];
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[ny][nx])
		{
			visited[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int k = 0; k <= 100; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] <= k)
					visited[i][j] = 1;
				else
					visited[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					visited[i][j] = 1;
					cnt[k - 1]++;
					dfs(i, j);
				}
			}
		}
	}

	int ans = *max_element(cnt, cnt + 100);

	cout << ans;

	return 0;
}