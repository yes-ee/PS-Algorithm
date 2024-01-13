#include <bits/stdc++.h>

using namespace std;

int n, b, a;
vector<int> v;
int cnt;
long long prefix_sum[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b >> a;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
		prefix_sum[i] = prefix_sum[i - 1] + v[i - 1];

	for (int i = n - a; i > 0; i--) {
		long long sum = prefix_sum[i] + (prefix_sum[i + a] - prefix_sum[i]) / 2;
		if (sum <= b) {
			cnt = i + a;
			break;
		}
	}

	if (cnt == 0) {
		for (int i = 1; i <= a; i++) {
			if (prefix_sum[i] / 2 > b)
				break;
			cnt = i;
		}
	}

	cout << cnt;
	return 0;
}