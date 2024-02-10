// union find

#include <iostream>

using namespace std;

int t, n, k, a, b, m;
int p[1000000];

int find(int u)
{
	if (p[u] == u)
		return u;

	return p[u] = find(p[u]);
}

void merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return;

	p[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cout << "Scenario " << i + 1 << ":\n";
		cin >> n >> k;

		for (int i = 0; i <= n; i++)
			p[i] = i;

		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			merge(a, b);
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			cout << (find(a) == find(b) ? "1" : "0") << "\n";
		}

		cout << "\n";
	}
}