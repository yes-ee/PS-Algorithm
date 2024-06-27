#include <iostream>
#include <string>

using namespace std;

string s;
int cnt = 1;

int main() {
	cin >> s;

	char pre;

	if (s.size())
		pre = s[0];

	for (int i = 1; i < s.size(); i++) {
		if (pre != s[i]) {
			cnt++;
			pre = s[i];
		}
	}

	cout << cnt / 2;

	return 0;
}