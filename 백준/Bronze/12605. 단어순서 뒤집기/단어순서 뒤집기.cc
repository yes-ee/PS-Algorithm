#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	cin >> n;
	cin.ignore();

	for (int i = 1; i <= n;i++) {
		cout<<"Case #"<<i<<": ";
		stack<string> st;
		getline(cin, s);

		int idx=0;
		for(int i=0; i<s.length();i++) {
			if (s[i] == ' ') {
				st.push(s.substr(idx,i - idx));
				idx=i+1;
			}
		}
		if(idx<s.length()) st.push(s.substr(idx));
		while(!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << "\n";
	}
}