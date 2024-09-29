#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a, sum;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
		sum += a;
	}

	sort(v.begin(), v.end());

	int pre = v[0];
	int mx_sum = pre;
	int cur_sum = pre;

	for (int i = 1; i < n; i++) {
		if (v[i] == pre) cur_sum += v[i];
		else {
			cur_sum = v[i];
			pre = v[i];
		}

		mx_sum = max(mx_sum, cur_sum); 
	}

	cout << sum + mx_sum << "\n";

	for (auto i : v) cout << i << " ";

	return 0;
}