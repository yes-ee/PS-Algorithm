#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		vector<string> v;
		string s;
		int flag = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		for (int i = 1; i < n; i++) {
			if (v[i - 1].length() >= v[i].length())
				continue;
			
			if (v[i - 1] == v[i].substr(0, v[i - 1].length())) {
				flag = 1;
				break;
			}
		}

		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}