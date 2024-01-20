#include <iostream>

using namespace std;

int n, m;
int parent[200];
int h[200];

int find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void Union(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)
		return;
	
	if (h[u] < h[v])
		swap(u, v);

	parent[v] = u;

	if (h[u] == h[v])
		h[u]++;
}

void init() {
	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				Union(i, j);
			}
		}
	}

	int a, flag = 0;
	cin >> a;
	int root = find(a - 1);

	for (int j = 1; j < m; j++) {
		cin >> a;
		if (find(a - 1) != root) {
			flag = 1;
			break;
		}
	}

	if (!flag)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}