#include <iostream>
#include <string>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s1, s2;

	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	cout << dp[s1.size()][s2.size()];

	return 0;
}