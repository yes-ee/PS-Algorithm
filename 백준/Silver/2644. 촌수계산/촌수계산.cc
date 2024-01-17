// bfs

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, a, b;

vector<int> v[101];
int visited[101];

int bfs() {
	queue<pair<int, int>> q;
	q.push({a, 0});
	visited[a] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == b)
			return cnt;

		for (int c: v[x]) {
			if (visited[c])
				continue;

			q.push({c, cnt + 1});
			visited[c] = 1;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << bfs();

	return 0;
}