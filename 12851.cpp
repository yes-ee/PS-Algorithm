#include <iostream>
#include <queue>
using namespace std;

int n, k, t, cnt, ans;
bool visited[100001];
queue<pair<int, int>> q;

void bfs()
{
	q.push({n, 0});

	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		visited[x] = true;

		if (cnt && x == k && t == ans)
			cnt++;
		
		if (!cnt && x == k) {
			ans = t;
			cnt++;
		}
		if ((x + 1) >= 0 && (x + 1) <= 100000 && !visited[x + 1])
			q.push({x + 1, t + 1});
		if ((x - 1) >= 0 && (x - 1) <= 100000 && !visited[x - 1])
			q.push({x - 1, t + 1});
		if ((x * 2) >= 0 && (x * 2) <= 100000 && !visited[x * 2])
			q.push({x * 2, t + 1});
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	bfs();
	cout << ans << "\n"
			 << cnt;
	return (0);
}