#include <iostream>

using namespace std;

int n, m;
int parent[1000000];

int find(int x) {
	if (parent[x] == x)
		return x;
	
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	if (x != y) {
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	while (m--) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0)
			Union(a, b);
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}