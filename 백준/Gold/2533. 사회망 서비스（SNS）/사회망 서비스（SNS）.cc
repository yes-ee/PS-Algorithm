#include <bits/stdc++.h>

using namespace std;

int n;
int dp[2][1000001];
vector<int> graph[1000001];
bool visited[1000001];

void dfs(int cur) {
	visited[cur] = 1;

	dp[0][cur] = 0;
	dp[1][cur] = 1;
	
	for (auto i : graph[cur]) {
		if (visited[i]) continue; // parent node

		dfs(i);

		dp[0][cur] += dp[1][i]; // 얼리어답터 x
		dp[1][cur] += min(dp[0][i], dp[1][i]); // 얼리어답터 o
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << min(dp[0][1], dp[1][1]);

	return 0;
}