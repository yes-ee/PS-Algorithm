// 가는 경로 구하기
// 제일 긴 경로 제외 합 구하기

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<pii> v[100001];
bool visited[100001];
int route[100001];
int cost[100001];
int n, a, b;
int sum;
int flag;

void dfs(int x) {
	if (flag) return;
	if (x == b) {
		flag = 1;
		int mx = 0;
		while (x) {
			sum += cost[x];
			mx = max(cost[x], mx);
			x = route[x];
		}
		sum -= mx;
		return;
	}

	for (auto i : v[x]) {
		int nx = i.first;
		int c = i.second;

		if (visited[nx]) continue;

		visited[nx] = true;
		route[nx] = x;
		cost[nx] = c;
		dfs(nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	int x, y, c;

	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> c;
		v[x].push_back({y, c});
		v[y].push_back({x, c});
	}

	visited[a] = true;
	dfs(a);

	cout << sum;

	return 0;
}