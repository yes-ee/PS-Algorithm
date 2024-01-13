#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result[100000];
bool visited[100000] = {false};
vector<int> arr[100000];
int cnt = 1;

void dfs(int n)
{
	result[n] = cnt;
	visited[n] = true;
	for (int i = 0; i < arr[n].size(); i++)
	{
		if (!visited[arr[n][i]])
		{
			cnt++;
			dfs(arr[n][i]);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, r, a, b;

	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
		sort(arr[i].begin(), arr[i].end());
	dfs(r - 1);
	for (int i = 0; i < n; i++)
		cout << result[i] << "\n";
		return (0);
}