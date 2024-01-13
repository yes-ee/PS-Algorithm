#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int n;
int arr[MAX];
int dp[MAX];
int max_len;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		max_len = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[j] > max_len)
				max_len = dp[j];
		}
		dp[i] = max_len+1;
	}

	cout << *max_element(dp, dp + n);

	return 0;
}