// binary search

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, h;
vector<int> a;
vector<int> b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h;

	int c, d;

	for (int i = 0; i < n / 2; i++) {
		cin >> c >> d;

		a.push_back(c);
		b.push_back(d);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int min_cnt = 1e9;
	int cnt = 0;

	for (int i = 1; i <= h; i++) {
		int ac = lower_bound(a.begin(), a.end(), i) - a.begin(); // i 이상인 수 개수
		int bc = lower_bound(b.begin(), b.end(), h - i + 1) - b.begin(); // (h i + 1) 이상인 수 개수

		int sum = n - ac - bc;
		if (min_cnt > sum) {
			min_cnt = sum;
			cnt = 1;
		} else if (min_cnt == sum) cnt++;
	}

	cout << min_cnt << " " << cnt;

	return 0;
}
