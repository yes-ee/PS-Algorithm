#include <iostream>
#include <vector>

using namespace std;

int n, a;
vector<pair<int, int>> v;
int dp[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 2;
	
	for (int i = 2; i <= 10000; i++) {
		int n = i;
		int cnt = 0;
		vector<int> p;
		int arr[i] = {0, };

		for (int j = 2; j * j <= i; j++) {
			if (n % j == 0) {
				p.push_back(j);
				n /= j;
			}

			while (n % j == 0) {
				n /= j;
			}
		}

		if (n > 1)
			p.push_back(n);

		for (int num : p) {
			for (int j = num; j < i; j += num) {
				arr[j] = 1;
			}
		}

		for (int j = 1; j < i; j++) {
			if (!arr[j])
				cnt++;
		}

		dp[i] = dp[i - 1] + cnt;
	}


	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;

		cout << dp[a] << "\n";
	}

	return 0;
}