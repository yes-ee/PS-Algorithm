// 조합
#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v, ans;

void dfs(int idx, int cnt) {
	if (cnt == 6) {
		for (auto c : ans) {
			cout << c << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < k; i++) {
		ans.push_back(v[i]);
		dfs(i + 1, cnt + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	while (k) {
		v.clear();
		int a;
		for (int i = 0; i < k; i++) {
			cin >> a;
			v.push_back(a);
		}
		dfs(0, 0);
		cout << "\n";
		cin >> k;
	}
}