#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 1000000
using namespace std;

int v, e, k;
vector<pair<int,int>> graph[MAX];	//초기 그래프 저장 배열
int visited[MAX];	//방문 여부 저장 배열
int dist[MAX];	//최단 거리 저장 배열

void dijkstra(void) {
	priority_queue<pair<int, int>> pq;
	pq.push({0, k});
	dist[k] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nc = graph[cur][i].second;

			if (dist[next] > cost + nc) {
				dist[next] = cost + nc;
				pq.push({-dist[next], next});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, b, c;

	cin >> v >> e >> k;

	for (int i = 1; i <= v; i++)
		dist[i] = INF;

	for (int i = 0; i < e; i++) { // 간선 정보 입력받음
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	
	return 0;
}