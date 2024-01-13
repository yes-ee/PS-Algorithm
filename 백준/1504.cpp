	// 다익스트라

	#include <iostream>
	#include <vector>
	#include <queue>
	#define INF 1e9

	using namespace std;

	int n, e;
	vector<pair<int, int>> v[801];

	vector<int> dijkstra(int s) {
		vector<int> dist(n + 1, INF);

		priority_queue<pair<int, int>> pq;

		dist[s] = 0;
		pq.push({0, s});

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i].first;
				int ncost = cost + v[cur][i].second;
				if (ncost < dist[next]) {
					dist[next] = ncost;
					pq.push({-ncost, next});
				}
			}
		}

		return dist;
	}

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin >> n >> e;

		for (int i = 0; i < e; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			v[a].push_back({b, c});
			v[b].push_back({a, c});
		}

		int u, v;
		cin >> u >> v;

		long long cost[2][3] = {{0, 0, 0}, {0, 0, 0}};
		vector<int> dist = dijkstra(1);
		vector<int> distu = dijkstra(u);
		vector<int> distv = dijkstra(v);

		cost[0][0] = dist[u];
		cost[1][0] = dist[v];
		cost[0][1] = distu[v];
		cost[1][1] = distv[u];
		cost[0][2] = distv[n];
		cost[1][2] = distu[n];

		long long ans = min(cost[0][0] + cost[0][1] + cost[0][2], cost[1][0] + cost[1][1] + cost[1][2]);

		if (ans >= INF) {
			cout << "-1\n";
			return 0;
		}

		cout << ans;

		return 0;
	}