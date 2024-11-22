#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[51][51];
int b[51][51];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			b[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j ++) {
			if (a[i][j] != b[i][j]) {
				ans++;
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						b[k][l] = (b[k][l] ? 0 : 1);
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << ans;

	return 0;
}