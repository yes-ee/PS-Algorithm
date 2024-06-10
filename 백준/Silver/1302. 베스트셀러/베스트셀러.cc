#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> m;
int n;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	while (n--) {
		string s;

		cin >> s;
		if (m[s]) m[s]++;
		else m[s] = 1;
	}

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	cout << v[0].first;

	return 0;
}