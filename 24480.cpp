#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100000] = {false};
vector<int> arr[100000];
int ans[100000];
int cnt = 1;

void dfs(int r)
{
	ans[r] = cnt;
	visited[r] = true;
	for (int i = 0; i < arr[r].size(); i++)
	{
		if (!visited[arr[r][i]])
		{
			cnt++;
			dfs(arr[r][i]);
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
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)	//내림차순 정렬
		sort(arr[i].begin(), arr[i].end(), greater<>());
	dfs(r - 1);
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";
	return (0);
}