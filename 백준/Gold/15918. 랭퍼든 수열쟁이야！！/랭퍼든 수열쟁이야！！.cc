#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int arr[24], num, cnt;

void dfs(int nxt) {
	if (nxt == 0) {
		cnt++;
		return;
	}

	if (nxt == num) {
		dfs(nxt - 1);
		return;
	}

	for (int i = 0; i < n * 2 - nxt - 1; i++) {
		if (arr[i] || arr[i + nxt + 1]) continue;

		arr[i] = arr[i + nxt + 1] = nxt;
		dfs(nxt - 1);
		arr[i] = arr[i + nxt + 1] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> y;

	num = y - x - 1;

	arr[y - 1] = arr[x - 1] = num;

	dfs(n);

	cout << cnt;

	return 0;	
}