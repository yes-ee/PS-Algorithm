#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int n, len, idx;
int arr[MAX];
int dp[MAX];
int pre[MAX];
int ans[MAX];

void solve(void) {
	int max_len;

	for (int i = 0; i < n; i++)
		pre[i] = -1;

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		max_len = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] > max_len) {
				max_len = dp[j];
				pre[i] = j;
			}
		}
		dp[i] = max_len + 1;
	}

	idx = max_element(dp, dp + n) - dp;
	len = dp[idx];

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve();

	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		ans[len - i - 1] = arr[idx];
		idx = pre[idx];
	}

	for (int i = 0; i < len; i++)
		cout << ans[i] << " ";

	return 0;
}