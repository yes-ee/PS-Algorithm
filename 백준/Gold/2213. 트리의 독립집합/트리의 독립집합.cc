#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> graph[10001];
int w[10001];
bool visited[10001];
vector<int> route[2][10001];
int dp[2][10001];

void dfs(int cur) {
	visited[cur] = 1;

	dp[0][cur] = 0;
	dp[1][cur] = w[cur];
	route[1][cur].push_back(cur);

	for (auto i : graph[cur]) {
		if (visited[i]) continue;

		dfs(i);
		// not select
		if (dp[1][i] > dp[0][i]) {
			dp[0][cur] += dp[1][i];
			for (auto j : route[1][i]) {
				route[0][cur].push_back(j);
			}
		} else {
			dp[0][cur] += dp[0][i];
			for (auto j : route[0][i]) {
				route[0][cur].push_back(j);
			}
		}
		// select
		dp[1][cur] += dp[0][i];
		for (auto j : route[0][i]) {
			route[1][cur].push_back(j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int a, b;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << max(dp[1][1], dp[0][1]) << "\n";

	if (dp[1][1] > dp[0][1]) {
		sort((route[1][1]).begin(), route[1][1].end());
		for (auto i : route[1][1]) {
			cout << i << " ";
		}
	} else {
		sort((route[0][1]).begin(), route[0][1].end());
		for (auto i : route[0][1]) {
			cout << i << " ";
		}
	}

	return 0;

}