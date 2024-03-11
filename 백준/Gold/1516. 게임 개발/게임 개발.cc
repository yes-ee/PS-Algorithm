// topology sort

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int arr[501];
int ans[501];
vector<int> v[501];
int in_degree[501];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> arr[i];	// time

		while (1) {
			cin >> a;
			if (a == -1) break;

			v[a].push_back(i);
			in_degree[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			ans[i] = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		int a = q.front();
		q.pop();

		for (int c : v[a]) {
			ans[c] = max(ans[c], arr[c] + ans[a]);
			in_degree[c]--;
			if (in_degree[c] == 0) q.push(c);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}