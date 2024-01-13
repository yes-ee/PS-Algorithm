#include <bits/stdc++.h>

using namespace std;

int parent[100001];
vector<int> arr[100001];
int n;

void dfs(int s) {
	for (int i = 0; i < arr[s].size(); i++) {
		int nx = arr[s][i];

		if (parent[nx] == 0) {
			parent[nx] = s;
			dfs(nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	int tmp = n - 1;
	while (tmp--) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

		return 0;
}