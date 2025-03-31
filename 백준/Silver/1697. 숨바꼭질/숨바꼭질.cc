#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100001];
int cnt[100001];

void bfs()
{
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == k)
		{
			cout << cnt[x];
			return;
		}
		if ((x + 1) >= 0 && (x + 1) <= 100000 && !visited[x + 1])
		{
			visited[x + 1] = true;
			q.push(x + 1);
			cnt[x + 1] = cnt[x] + 1;
		}
		if ((x - 1) >= 0 && (x - 1) <= 100000 && !visited[x - 1])
		{
			visited[x - 1] = true;
			q.push(x - 1);
			cnt[x - 1] = cnt[x] + 1;
		}
		if ((x * 2) >= 0 && (x * 2) <= 100000 && !visited[x * 2])
		{
			visited[x * 2] = true;
			q.push(x * 2);
			cnt[x * 2] = cnt[x] + 1;
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
	return (0);
}