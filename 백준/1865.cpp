#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int t;
int n, m, w;
long long d[501];
vector<pair<int, pair<int, int>>> edges;

bool bellman(int s) {
	d[s] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int u = edges[j].first;
			int v = edges[j].second.first;
			int w = edges[j].second.second;

			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;

				if (i == n-1)
					return true;
			}
		}
	}

	return false;
}

int main() {
	cin >> t;
	while (t--) {
		// init
		edges.clear();
		for (int i = 0; i < 501; i++)
			d[i] = INF;

		cin >> n >> m >> w;

		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;

			edges.push_back({u, {v, w}});
			edges.push_back({v, {u, w}});
		}

		for (int i = 0; i < w; i++) {
			int u, v, w;
			cin >> u >> v >> w;

			edges.push_back({u, {v, -w}});
		}

		if (bellman(1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}