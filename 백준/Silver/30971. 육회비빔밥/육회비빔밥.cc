#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[10];
int b[10];
int c[10];
int sum, ans = -1;
int visited[10];

void dfs(int cnt, int pre) {
	if (cnt == n) {
		ans = max(sum, ans);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		if (c[i] * c[pre] > k) continue;

		int taste = a[pre] * b[i];

		visited[i] = 1;
		sum += taste;
		dfs(cnt + 1, i);
		sum -= taste;
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		dfs(1, i);
		visited[i] = 0;
	}

	cout << ans;

	return 0;
}