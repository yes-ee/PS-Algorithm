#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int n, max_len;
int arr[MAX];
int dp[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
	}

	for (int i = 1; i < MAX; i++) {
		if (arr[i] == 0)
			continue;
		max_len = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] > max_len)
				max_len = dp[j];
		}
		dp[i] = max_len + 1;
	}

	cout << n - *max_element(dp, dp + MAX - 1);

	return 0;
}
