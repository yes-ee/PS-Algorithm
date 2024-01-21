// union find
// size 저장
// map에 string -> index 저장

#include <iostream>
#include <map>
#include <string>

using namespace std;

int t, f, idx;
map<string, int> m;
int parent[200000];
int h[200000];
int s[200000];

int find(int a) {
	if (parent[a] == a)
		return a;

	return parent[a] = find(parent[a]);
}

int Union(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return s[u];
	
	if (h[u] < h[v])
		swap(u, v);

	parent[v] = u;
	s[u] += s[v];

	if (h[u] == h[v])
		h[u]++;

	return s[u];
}

void init() {
	for (int i = 0; i < 200000; i++) {
		parent[i] = i;
		h[i] = 1;
		s[i] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> f;
		init();
		for (int i = 0; i < f; i++) {
			string a, b;
			cin >> a >> b;
			auto ita = m.find(a);
			auto itb = m.find(b);
			int idxa, idxb;

			if (ita == m.end()) {
				idxa = idx;
				m.insert({a, idx++});
			} else {
				idxa = m[a];
			}

			if (itb == m.end()) {
				idxb = idx;
				m.insert({b, idx++});
			} else {
				idxb = m[b];
			}

			cout << Union(idxa, idxb) << "\n";
		}
	}

	return 0;
}