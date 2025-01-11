#include <bits/stdc++.h>

using namespace std;

int n;
string arr[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i =0;i<n;i++) cin >> arr[i];
	int len = arr[0].length();

	for (int i = 1;i <= len;i++) {
		set<string> s;
		string st;

		for(int j = 0; j < n; j++) {
			st=arr[j].substr(len-i, i);
			if (s.count(st)) break;
			s.insert(st);
		}
		if (s.size() == n) {
			cout << i;
			return 0;
		}
	}

	return 0;
}