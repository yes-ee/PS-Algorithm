#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, len;
vector<int> v;
vector<int> input;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int num : v) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < len; i++) {
		v.push_back(input[i]);
		dfs(i, cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (find(input.begin(), input.end(), a) == input.end()) {
			input.push_back(a);
			len++;
		}
	}

	sort(input.begin(), input.end());

	dfs(0, 0);

	return 0;
}