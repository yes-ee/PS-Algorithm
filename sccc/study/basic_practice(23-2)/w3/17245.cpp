#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, idx = 1, ans;
long long t, cnt, total;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	int tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 0)
				continue;
			v.push_back(tmp);
			total += tmp;
		}
	}

	sort(v.begin(), v.end());
	long long len = v.size();
	long long goal = total / 2 + total % 2;

	if (len == 0) {
		cout << "0\n";
		return 0;
	}

	long long start, end, mid;

	start = 1;
	end = v[len - 1];

	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < len; i++) {
			if (v[i] >= mid)
				cnt += mid;
			else
				cnt += v[i];
		}

		if (cnt >= goal) {
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	cout << ans;

	return 0;
}