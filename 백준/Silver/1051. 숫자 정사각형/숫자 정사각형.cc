#include <bits/stdc++.h>

using namespace std;

int n, m, len, ans = 1;
int arr[50][50];
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	len = min(n, m);

	for (int k = len - 1; k >= 1; k--) {
		for (int i = 0; i < n - k; i++) {
			for (int j = 0; j < m - k; j++) {
				int num = arr[i][j];
				if (arr[i][j + k] != num) continue;
				if (arr[i + k][j] != num) continue;
				if (arr[i + k][j + k] != num) continue;

				ans = k + 1;
				cout << ans * ans;
				return 0;
			}
		}
	}

	cout << ans;

	return 0;
}