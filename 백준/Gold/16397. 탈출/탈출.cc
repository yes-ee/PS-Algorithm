#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int n, t, g;
int visited[100001];

int bfs() {
	queue<pii> q;
	q.push({n, 0});
	visited[n] = 1;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		int nx;
		q.pop();

		// a
		nx = num + 1;
		if (nx < 100000 && !visited[nx]) {
			if (nx == g) {
				return cnt + 1;
			}

			visited[nx] = 1;
			if ((cnt + 1) != t) {
				q.push({nx, cnt + 1});
			}
		}

		// b
		nx = num * 2;
		if (nx >= 100000 || !nx) continue;
		int div = 10000;
		while (div) {
			if (nx / div) {
				nx -= div;
				break;
			}
			div /= 10;
		}

		if (!visited[nx]) {
			if (nx == g) {
				return cnt + 1;
			}

			visited[nx] = 1;
			if ((cnt + 1) != t)
				q.push({nx, cnt + 1});
		}
	}
	return -1;
}

int main() {
	cin >> n >> t >> g;

	if (n == g) {
		cout << 0;
		return 0;
	}

	int ret = bfs();
	
	if (ret < 0) cout << "ANG";
	else cout << ret;
	return 0;
}