#include <iostream>
#include <string>

using namespace std;

int cnt, sum;

int main() {
	string s;
	char pre = 'a';
	cin >> s;
	for (char c : s) {
		if (c == ')') {
			if (pre == '(') {
				cnt--;
				sum += cnt;
			}
			else {
				sum++;
				cnt--;
			}
		}
		else {
			cnt++;
		}
		pre = c;
	}

	cout << sum;

	return 0;
}