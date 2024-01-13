#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k, n, cnt, ans;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++)	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	long long start = 1;
	long long end = v[k - 1];
	long long mid;

	while (start <= end) {
		cnt = 0;

		mid = (start + end) / 2;

		for (int i = 0; i < k; i++) {
			cnt += v[i] / mid;
		}

		if (cnt >= n) {
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	cout << ans;

	return 0;
}