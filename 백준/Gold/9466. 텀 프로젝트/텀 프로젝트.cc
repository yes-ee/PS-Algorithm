// dfs, cycle

#include <iostream>

using namespace std;

int arr[100001];
int visited[100001];
int t, cnt, cy, n;

void dfs(int idx) {
	if (visited[idx]) {
		// cycle
		if (visited[idx] == cy) {
			int cur = arr[idx];
			
			cnt++;

			while (cur != idx) {
				cur = arr[cur];
				cnt++;
			}

		}
		return;
	}

	visited[idx] = cy;
	dfs(arr[idx]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> n;

		cnt = 0;
		cy = 0;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = 0;
		}
		
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			cy++;
			dfs(i);
		}

		cout << n - cnt << "\n";
	}

	return 0;
}