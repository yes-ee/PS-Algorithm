#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, n, dis;
vector<string> v, ans;

int check() {
	int tmp = 0;

	for (int i = 0; i < 4; i++) {
		if (ans[0][i] != ans[1][i])
			tmp++;
		if (ans[0][i] != ans[2][i])
			tmp++;
		if (ans[1][i] != ans[2][i])		
			tmp++;
	}

	return tmp;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		int tmp = check();
		dis = min(tmp, dis);
		return;
	}

	for (int i = idx; i < v.size(); i++) {
		ans.push_back(v[i]);
		dfs(i + 1, cnt + 1);
		ans.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		v.clear();
		ans.clear();
		dis = 1e9;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			v.push_back(s);
		}

		if (n > 32) {
			cout << "0\n";
		} else {
			dfs(0, 0);
			cout << dis << "\n";
		}
	}

	return 0;
}