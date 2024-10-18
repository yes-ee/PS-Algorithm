#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, cnt;
int parent[101];
int graph[101][101];
vector<vector<int>> v(101);
vector<int> ans;

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		for (int j = 1; j <= n; j++)
			graph[i][j] = INF;
	}
}

int find(int a) {
	if (parent[a] == a) return a;

	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	int a, b;

	init();

	while (m--) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;

		// 그룹 구성
		merge(a, b);
	}

	for (int i = 1; i <= n; i++) {
		int p = find(i);
		v[p].push_back(i);
	}

	for (auto grp : v) {
		if (grp.size()) cnt++;
	}

	cout << cnt << "\n";

	for (auto grp : v) {
		if (grp.size() == 0) continue;

		// floyd
		for (int k : grp) {
			graph[k][k] = 0;
			for (int i : grp) {
				for (int j : grp) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}

		int lead = grp[0];
		int ms = INF;
		for (auto i : grp) {
			int mx = 0;
			for (auto j : grp) {
				mx = max(mx, graph[i][j]);
			}
			if (mx < ms) {
				lead = i;
				ms = mx;
			}
		}
		ans.push_back(lead);
	}

	sort(ans.begin(), ans.end());

	for (auto i : ans)
		cout << i << "\n";

	return 0;
}