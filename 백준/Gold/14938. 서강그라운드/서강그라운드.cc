// 다익스트라
#include <iostream>
#include <queue>

using namespace std;

int n, m, r, ans;
vector<int> item;
vector<pair<int, int>> v[101];

vector<int> dijk(int start) {
	vector<int> dist(n + 1, 1e9);
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		int x = pq.top().second;
		int c = -pq.top().first;
		pq.pop();

		for (auto ch : v[x]) {
			int nx = ch.first;
			int nc = c + ch.second;

			if (nc < dist[nx]){
				dist[nx] = nc;
				pq.push({-nc, nx});
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;

	item.push_back(0);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		item.push_back(a);
	}

	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	for (int i = 1; i <= n; i++) {
		vector<int> ret = dijk(i);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (ret[i] <= m) {
				cnt += item[i];
			}
		}

		ans = max(cnt, ans);
	}

	cout << ans;

	return 0;
}