// bitmasking

#include <iostream>
#include <string>

using namespace std;

int n, k;
int arr[50];
string s;
int ans, cnt, word;

void re(int idx, int len) {
	if (len == k) {
		// count readable word
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((word | arr[i]) == word) cnt++;
		}
		ans = max(cnt, ans);
		return;
	}

	for (int i = idx; i < 26 - k + len + 1; i++) {
		if (1 << i & word) continue;

		// select
		word |= 1 << i;
		re(i + 1, len + 1);
		word &= ~(1 << i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	if (k < 5) {
		cout << 0;
		return 0;
	}

	string s = "acint";

	for (char c : s) {
		word |= (1 << c - 'a');
	}

	k -= 5;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			int c = s[j] - 'a';
			arr[i] |= (1 << c); // add alphabet
		}
	}

	re(0, 0);

	cout << ans;

	return 0;
}