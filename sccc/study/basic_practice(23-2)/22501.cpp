// 재귀

#include <iostream>
#include <string>

using namespace std;

int t, cnt;
string s;

int recursion(int l, int r) {
	cnt++;
	if (l >= r)
		return 1;

	if (s[l] != s[r])
		return 0;
	else
		return recursion(l + 1, r - 1);
}

int isPalindrome() {
	return recursion(0, s.length() - 1);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> s;
		cout << isPalindrome() << " " << cnt << "\n";
	}

	return 0;
}