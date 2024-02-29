// mst
// kruskal

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, cnt;
long long sum;
vector<pair<int, pair<int, int>>> g;
int p[100000];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;

	for (int i = 0; i <= V; i++)
		p[i] = i;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		g.push_back({c, {a, b}});
	}

	sort(g.begin(), g.end());

	for (int i = 0; i < g.size(); i++) {
		int u = g[i].second.first;
		int v = g[i].second.second;

		if (find(u) == find(v)) continue;

		merge(u, v);
		sum += g[i].first;

		cnt++;
		if (cnt == V - 1) break;
	}

	cout << sum;

}