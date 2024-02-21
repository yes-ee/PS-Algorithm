#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dp[15001];
int n, m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int cur: v) {
		int pre[15001];
		for (int i = 0; i < 15001; i++)
			pre[i] = dp[i];
		for (int i = 1; i < 15001; i++) {
			if (pre[i]) {
				dp[i + cur] = 1;
				dp[abs(i - cur)] = 1;
			}
		}
		dp[cur] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (a > 15000)
			cout << "N\n";
		else if (dp[a])
			cout << "Y\n";
		else
			cout << "N\n";
	}

	return 0;
}