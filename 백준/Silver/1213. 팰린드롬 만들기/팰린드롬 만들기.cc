#include <bits/stdc++.h>

using namespace std;

string s;
vector<char> v;
int cnt[26];
int odd = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A']++;
	}

	int mid = s.size() / 2;
	int mid_char = -1;


	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2) {
			odd++;
			mid_char = i;
			cnt[i]--;
		}
	}

	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0) {
			for (int j = 0; j < cnt[i] / 2; j++) {
				v.push_back(i + 'A');
			}
		}
	}

	for (auto i : v) cout << i;
	if (mid_char != -1) cout << (char)(mid_char + 'A');
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i];

	return 0;
}