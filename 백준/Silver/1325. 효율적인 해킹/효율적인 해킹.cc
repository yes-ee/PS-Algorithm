#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[10001];
int visited[10001];
int cnt[10001];
int ans, val;

void dfs(int n) {
	visited[n] = 1;
	val++;

	for (int c : v[n]) {
		if (visited[c]) continue;

		dfs(c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		val = 0;
		for (int j = 1; j <= n; j++)
			visited[j] = 0;
		dfs(i);
		cnt[i] = val;
		ans = max(ans, cnt[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (ans == cnt[i])
			cout << i << " ";
	}

	return 0;

}