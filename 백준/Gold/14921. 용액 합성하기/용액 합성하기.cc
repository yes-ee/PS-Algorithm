#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int ans = 1e9;

int main() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	int st = 0;
	int end = v.size() - 1;

	while (st < end) {
		int sum = v[st] + v[end];
		if (abs(sum) < abs(ans)) ans = sum;

		if (sum == 0) break;
		if (sum > 0) end--;
		else st++;
	}

	cout << ans;

	return 0;
}