#include <iostream>
#include <string>
#include <stack>

using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while(t--) {
		string s;
		int fin = 0;
		stack<char> st;
		cin >> s;
		int len = s.length();

		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				st.push(s[i]);
			} else { // )
				if (st.empty()) {
					fin = 1;
					break;
				} else {
					st.pop();
				}
			}
		}
		if (fin || !st.empty()) {
			cout << "NO\n";
		} else if (!fin) {
			cout << "YES\n";
		}
	}

	return 0;
}