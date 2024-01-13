#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string s;
stack<char> st;

void solve(void) {
	while (!st.empty())
		st.pop();

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')	//'('인 경우만 스택에 저장
			st.push('(');
		else {	//')'인 경우 스택이 비어있는지 확인하고 pop
			if (st.empty()) {
				cout << "NO\n";
				return;
			}
			st.pop();
		}
	}

	if (!st.empty())
		cout << "NO\n";
	else
		cout << "YES\n";

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		solve();
	}

	return 0;
}