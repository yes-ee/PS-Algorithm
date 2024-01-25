#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	stack<char> st1;
	stack<char> st2;
	int n;
	cin >> s >> n;
	for (char c : s)
		st1.push(c);
	int idx = s.length();
	while (n--) {
		char a, b;
		cin >> a;
		if (a == 'P') {
			cin >>b;
			st1.push(b);
		} else if (a == 'L') {
			if (!st1.empty()) {
				st2.push(st1.top());
				st1.pop();
			}
		} else if (a == 'D') {
			if (!st2.empty()) {
				st1.push(st2.top());
				st2.pop();
			}
		} else {
			if (!st1.empty())
				st1.pop();
		}
	}

	while (!st1.empty()) {
		st2.push(st1.top());
		st1.pop();
	}

	while (!st2.empty()) {
		cout << st2.top();
		st2.pop();
	}

	return 0;
}