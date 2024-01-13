#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;

	while (1) {
		cin >> s;
		if (s == "0")
			break;
		int len = s.length();
		int flag = 1;
		for (int i = 0; i < len / 2; i++) {
			if (s[i] != s[len - i - 1]) {
				cout << "no\n";
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "yes\n";
	}
	return 0;
}