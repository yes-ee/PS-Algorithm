#include <bits/stdc++.h>

using namespace std;

int arr[8];
int visited[8];
vector<int> v;
int n, m;

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		v.push_back(arr[i]);
		visited[i] = 1;
		solve(cnt + 1);
		v.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	solve(0);

	return 0;
}