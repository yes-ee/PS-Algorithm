// dfs
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, ans;
vector<pair<int, int>> graph[100001];
int visited[100001];

bool dfs(int start, int cost) {
	visited[start] = 1;
	
	if (start == y) {
		return true;
	}

	for (auto c: graph[start]) {
		int nx = c.first;
		int nc = c.second;

		if (visited[nx] || nc < cost) continue;

		if (dfs(nx, cost))
			return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	cin >> x >> y;

	long long low = 0;
	long long high = 2000000000;
	long long mid = (low + high) / 2;

	while (low <= high) {
		long long mid = (low + high) / 2;

		for (int i = 0; i < 100001; i++)
			visited[i] = 0;

		if (dfs(x, mid)) {
			low = mid + 1;
			ans = mid;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}