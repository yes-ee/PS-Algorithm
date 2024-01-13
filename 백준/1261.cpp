#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;
vector<pair<int, int>> v[10000];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<int> dijkstra() {
	vector<int> dist(n * m, INF);
	priority_queue<pair<int, int>> pq;

	dist[0] = 0;
	pq.push({0, 0});

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
	cin >> n >> m;
	int map[m][n];

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				int w = 0;

				if (map[ny][nx] == '1')
					w = 1;

				v[n * i + j].push_back({n * ny + nx, w});
			}
		}
	}
	
	vector<int> dist = dijkstra();
	cout << dist[n * m - 1];

	return 0;
}