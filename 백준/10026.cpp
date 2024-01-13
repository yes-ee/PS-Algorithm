#include <iostream>
#include <string>
#include <string.h>
#define MAX 100
using namespace std;

char arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, ans;

void dfs(int y, int x, char c)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[ny][nx] && (c == arr[ny][nx]))
		{
			visited[ny][nx] = 1;
			dfs(ny, nx, c);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = 1;
				ans++;
				dfs(i, j, arr[i][j]);
			}
		}
	}

	cout << ans << " ";

	memset(visited, 0, sizeof(bool) * MAX * MAX);
	ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = 1;
				ans++;
				dfs(i, j, arr[i][j]);
			}
		}
	}

	cout << ans;

	return 0;
}