// 한 정점에서 다른 정점으로 가는 최소 비용 구하기
// 다익스트라

#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;
int a, b;
vector<pair<int, int>> adj[1001];
vector<int> res;
int path[1001];
int visited[1001];

vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;  // 비용, 정점

    dist[start] = 0;    // 시작지점 비용 0
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first; // 비용
        int cur = pq.top().second;  // 현재 정점
        pq.pop();
        if (visited[cur])
            continue;
        visited[cur] = 1;

        for (int i = 0; i< adj[cur].size(); i++) {
            int nxt = adj[cur][i].first;
            int nxt_cost = cost + adj[cur][i].second;

            if (nxt_cost < dist[nxt]) {
				dist[nxt] = nxt_cost;
				path[nxt] = cur;
                pq.push({-nxt_cost, nxt});
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m;

    int a, b, c;

    for (int i  = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    cin >> a >> b;

    if (a == b) {
        cout << "0\n1\n" << a;
        return 0;
    }

    vector<int> dist = dijkstra(a);

    vector<int> p;
    int cur = b;
    int nxt = path[b];
    int cnt = 0;

    while (1) {
        p.push_back(cur);

        if (cur == a) {
            break;
			        cout << cur << " " << nxt << endl;
        }

        cur = nxt;
        nxt = path[nxt];

        cnt++;
    }

    cout << dist[b] << "\n";
    cout << p.size() << "\n";

    for (int idx = p.size() - 1; idx >= 0; idx--) {
        cout << p[idx] << " ";
    }

    return 0;
}