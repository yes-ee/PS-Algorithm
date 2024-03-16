#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii=pair<int, int>;

int n, m, x, y, k;
vector<pii> need[101];	//번호, 개수
int bn[101][101];	//기본 부품
queue<int> q;
int b[101], in[101];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> k;
		need[y].push_back({x, k});
		in[x]++;
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0 && need[i].size() != 0) {
			b[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (pii c: need[x]) {
			int nx = c.first;
			int cnt = c.second;
			if (b[x])
				bn[nx][x] += cnt;
			else {
				for (int i = 1; i< n; i++)
					bn[nx][i] += bn[x][i] * cnt;
			}
			in[nx]--;
			if (in[nx] == 0)
				q.push(nx);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!b[i]) continue;

		cout << i << " " << bn[n][i] << "\n";
	}

	return 0;
}