#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	int cnt = 1;
	int end;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), cmp);

	end = v[0].second;

	for (int i = 1; i < n; i++) {
		if (v[i].first >= end) {
			cnt++;
			end = v[i].second;
		}
	}

	cout << cnt;

	return 0;
}