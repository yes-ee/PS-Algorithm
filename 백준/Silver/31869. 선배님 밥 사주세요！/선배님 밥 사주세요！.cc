#include <bits/stdc++.h>

using namespace std;

string s;
int n, w, d, p;
map<string, int> m;
vector<pair<int, string>> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s >> w >> d >> p;
		v.push_back({w * 7 + d, s});
		m[s] = p;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cin >> s >> p;

		if (m[s] > p) m.erase(s);
	}

	int cnt = 0;
	int ans = 0;
	int day = -1;

	for (auto i : v) {
		if (m.count(i.second) == 0) {
			continue;
		}
		if (day == -1) {
			cnt++;
			day = i.first;
		} else {
			if (i.first == day) continue;
			else if (i.first == day + 1) {
				cnt++;
				day = i.first;
			} else {
				ans = max(ans, cnt);
				day = i.first;
				cnt = 1;
			}
		}
	}

	ans = max(ans, cnt);

	cout << ans;

	return 0;
}