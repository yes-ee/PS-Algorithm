#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;
int n, sum, node;
vector<p> arr[10001];
int visited[10001];

//가장 거리가 먼 정점 구하기
void dfs(int s, int len) {
	if (sum < len) {
		sum = len;
		node = s;
	}

	for (int i = 0; i < arr[s].size(); i++) {
		int nx = arr[s][i].first;

		if (!visited[nx]) {
			visited[nx] = 1;
			dfs(nx, len + arr[s][i].second);
			visited[nx] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		arr[u].push_back({v, w});
		arr[v].push_back({u, w});
	}

	if (n == 1) {
		cout << "0";
		return 0;
	}

	visited[1] = 1;
	dfs(1, 0);

	sum = 0;
	memset(visited, 0, sizeof(visited));
	visited[node] = 1;
	dfs(node, 0);

	cout << sum;

		return 0;
}