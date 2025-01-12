#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int arr[n + 1][5];
	int input;
	for (int i = 1; i <= n;i++) {
		for (int j = 0;j<5;j++) {
			cin >> arr[i][j];
		}
	}

	set<int> s[n + 1];
	for (int i = 0;i<5;i++) {
		vector<int> v[10];
		int cl;
		for (int j = 1; j<=n;j++) {
			cl = arr[j][i];
			v[cl].push_back(j);
		}

		for (int j =1; j <=9;j++) {
			for (auto p : v[j]) {
				for (auto sm : v[j]) {
					s[p].insert(sm);
				}
			}
		}
	}

	int mx = 1;
	for (int i = 2; i <= n;i++) {
		if (s[i].size() > s[mx].size()) mx = i;
	}

	cout << mx;
	return 0;
}