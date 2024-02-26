#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2, ans;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2;

	int l1 = s1.length();
	int l2 = s2.length();

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			} else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	int i = l1;
	int j = l2;

	while(dp[i][j]) {
		if (dp[i][j - 1] == dp[i][j])
			j--;
		else if (dp[i - 1][j] == dp[i][j])
			i--;
		else {
			ans += s1[i - 1];
			i--;
			j--;
		}
	}

	reverse(ans.begin(), ans.end());

	cout << dp[l1][l2] << "\n";

	if (dp[l1][l2])
		cout << ans;

	return 0;
}