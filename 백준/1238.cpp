// tag: 다익스트라
// x->각 정점까지 거리 - 역방향 그래프 활용

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

const int INF = 1e9;

using namespace std;

typedef pair<int, int> pii;

int n, x, m;
vector<pii> map[1000];
vector<pii> rmap[1000];
int time[1000];	// 총 소요 시간 저장
int dist[1000];

void dijkstra(int s, vector<pii> map[]) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	pq.push({0, s});
	dist[s] = 0;

	while (!pq.empty()) {
		pii top = pq.top();
		pq.pop();

		int cur_dist = top.first;
		int cur = top.second;

		if (dist[cur] < cur_dist)
			continue;

		for (pii nxt_edge : map[cur]) {
			int nxt = nxt_edge.first;

			if (dist[nxt] > dist[cur] + nxt_edge.second) {
				dist[nxt] = dist[cur] + nxt_edge.second;
				pq.push({dist[nxt], nxt});
			}
		}
	
	}
	for (int i = 0; i < n; i++) {
		time[i] += dist[i];
	}
}

int main() {
	cin >> n >> m >> x;
	x--;	

	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;

		map[u].push_back({v, w});
		rmap[v].push_back({u, w});
	}

	for (int j = 0; j < n; j++) {
		dist[j] = INF;
	}
	dijkstra(x, map);

	for (int j = 0; j < n; j++) {
		dist[j] = INF;
	}
	dijkstra(x, rmap);
	
	cout << *max_element(begin(time), time + n);

	return 0;
}