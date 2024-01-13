#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;

int n, m, a, b;
vector<pii> g[1000];
priority_queue<pii, vector<pii>, greater<pii>> pq;	//{해당 정점까지 거리, 해당 정점}
int dist[1000];	//시작 정점에서부터 각 정점까지 최단 거리

int main() {
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v, w});
	}

	cin >> a >> b;
	a--;
	b--;

	for (int i = 0; i < n; i++) {
		dist[i] = INF;
	}

	pq.push({0, a});
	dist[a] = 0;

	while (!pq.empty()) {
		pii top = pq.top();
		pq.pop();

		int cur_dist = top.first;
		int cur = top.second;

		if (dist[cur] < cur_dist)
			continue;
		for (pii next_edge : g[cur]) {
			int next = next_edge.first;
			// 지금 정점을 거쳐가는 게 더 빠르면 갱신
			if (dist[next] > dist[cur] + next_edge.second) {
				dist[next] = dist[cur] + next_edge.second;
				pq.push({dist[next], next});
			}
		}
	}

	cout << dist[b];

	return 0;
}