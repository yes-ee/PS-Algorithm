#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
string s, ans;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	char c = v[0][0];
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (c == v[i][0]) cnt++;
		else {
			c = v[i][0];
			cnt = 1;
		}

		if (cnt == 5) ans += c;
	}

	if (ans.length()) cout << ans;
	else cout << "PREDAJA";

	return 0;
}