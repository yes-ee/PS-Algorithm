// tree

#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
bool visited[100001];
int nodes[100001];
vector<vector<int>> v(100001);

int dfs(int node) {
	visited[node] = true;
	nodes[node] = 1;

	for (int child : v[node]) {
		if (visited[child]) continue;

		nodes[node] += dfs(child);
	}

	return nodes[node];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> q;

	// input
	for (int i = 0; i < n - 1; i++) {
		int a, b;

		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// make tree
	dfs(r);

	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		cout << nodes[a] << "\n";
	}

	return 0;
}