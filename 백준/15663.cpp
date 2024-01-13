#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> ans;
vector<int> num;
int visited[8];

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i] || tmp == num[i])
			continue;
		ans.push_back(num[i]);
		tmp = num[i];
		visited[i] = 1;
		solve(cnt + 1);
		visited[i] = 0;
		ans.pop_back();
	}
}

int main() {
	cin >> n >> m;

	int tmp = n;

	while (tmp--) {
		int input;
		cin >> input;
		num.push_back(input);
	}

	sort(num.begin(), num.end());

	solve(0);

	return 0;
}