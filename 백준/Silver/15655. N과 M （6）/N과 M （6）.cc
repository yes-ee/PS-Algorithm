#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int nm : ans) {
			cout << nm << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		ans.push_back(v[i]);
		dfs(i + 1, cnt + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	dfs(0, 0);
}