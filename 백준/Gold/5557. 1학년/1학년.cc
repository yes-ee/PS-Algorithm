#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> v;
ll dp[100][21];

bool check(int num) {
	if (num < 0 || num > 20) return false;
	return true;
}

int main() {
	cin >> n;

	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	dp[0][v[0]]++;

	for (int i = 1; i < n - 1; i++) {
		int num = v[i];
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (check(j + num))
					dp[i][j + num] += dp[i - 1][j];
				if (check(j - num))
					dp[i][j - num] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n-2][v[n-1]];

	return 0;
}