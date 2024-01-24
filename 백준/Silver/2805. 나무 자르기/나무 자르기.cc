// paramatric search

#include <iostream>
#include <vector>

using namespace std;

long long n, m, ans;
vector<int> v;

int fn(int mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long tmp = v[i] - mid;
		if (tmp > 0)
			sum += tmp;
	}

	if (sum >= m) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	long long low = 0;
	long long high = 2000000000;

	while (low <= high) {
		long long mid = (low + high) / 2;

		if (fn(mid)) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}