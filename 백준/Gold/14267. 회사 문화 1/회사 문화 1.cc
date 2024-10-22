#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[1000001];
int sum[100001];
bool visited[100001];

void dfs(int cur) {
	visited[cur] = true;

	for (auto j : v[cur]) {
		if (visited[j]) continue;
		
		sum[j] += sum[cur];
		dfs(j);
	}
}

void input() {
	int a, b;

	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a == -1) continue;

		v[a].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		sum[a] += b;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;

	input();
	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << sum[i] << " ";
	}

	return 0;
}