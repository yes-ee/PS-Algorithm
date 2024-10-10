#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> rv;

int main() {
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	for (int i = n - 1; i >= 0; i--) {
		rv.push_back(v[i]);
	}

	int lst_idx = n - 1;
	int cnt= 0;

	for (int i = 0; i < n; i++) {
		int cur_idx = max_element(v.begin(), v.end() - i) - v.begin();

		cnt += lst_idx - cur_idx;

		for (int j = cur_idx; j < lst_idx; j++) {
			v[j] = v[j + 1];
		}

		lst_idx--;
	}

	int ans = cnt;

	lst_idx = n - 1;
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		int cur_idx = max_element(rv.begin(), rv.end() - i) - rv.begin();

		cnt += lst_idx - cur_idx;

		for (int j = cur_idx; j < lst_idx; j++)
		{
			rv[j] = rv[j + 1];
		}

		lst_idx--;
	}

	ans = min(ans, cnt + 1);

	cout << ans;

	return 0;
}