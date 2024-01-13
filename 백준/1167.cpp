#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> p;
int n, sum, node;
vector<p> arr[100001];
int visited[100001];

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
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int u, v, w;
		cin >> u;

		while (1) {
			cin >> v;
			if (v == -1)
				break;
			cin >> w;
			arr[u].push_back({v, w});
		}
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