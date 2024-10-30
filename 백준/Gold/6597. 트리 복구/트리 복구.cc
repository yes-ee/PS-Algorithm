#include <bits/stdc++.h>

using namespace std;

char pre[26];
char in[26];
map<char, int> idx;

void post_order(int pre_st, int pre_end, int in_st, int in_end) {
	if (pre_st > pre_end || in_st > in_end) return;

	int root_idx = idx[pre[pre_st]];
	int left_size = root_idx - in_st;
	int right_size = in_end - root_idx;

	post_order(pre_st + 1, pre_st + left_size, in_st, root_idx - 1);
	post_order(pre_st + left_size + 1, pre_end, root_idx + 1, in_end);

	cout << pre[pre_st];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			pre[i] = s[i];
		}
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			in[i] = s[i];
			idx[s[i]] = i;
		}

		post_order(0, s.length() - 1, 0, s.length() - 1);
		cout << "\n";

		if (cin.eof()) break;
	}

	return 0;
}