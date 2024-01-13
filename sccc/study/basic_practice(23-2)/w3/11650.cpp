#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}