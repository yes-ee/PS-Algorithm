// 자신이 우수마을이거나
// 우수마을이 아니면 인접 마을 중에 하나 이상이 우수마을
// 우수마을끼리 인접할 수 없음
// 선정 마을 주민 수 최대

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> graph[10001];
int dp[2][10001];
int person[10001];
bool visited[10001];

void dfs(int cur) {
	visited[cur] = true;

	dp[0][cur] = 0;
	dp[1][cur] = person[cur];

	for (auto i : graph[cur]) {
		if (visited[i]) continue;

		dfs(i); // i까지 최대 주민 수 값 받아옴
		// 내가 우수 마을이 아님 -> 주변 우수마을이거나, 아니거나
		dp[0][cur] += max(dp[1][i], dp[0][i]);
		// 내가 우수 마을 -> 주변 다 우수 마을 아님
		dp[1][cur] += dp[0][i];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> person[i];

	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1); // 1번 마을부터 시작

	cout << max(dp[0][1], dp[1][1]);

	return 0;
}