#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, input, a;
	string s;
	stack<int> st;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> input;
			st.push(input);
		}
		else if (s == "pop") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				a = st.top();
				st.pop();
				cout << a << "\n";
			}
		}
		else if (s == "size") {
			cout << st.size() << "\n";
		}
		else if (s == "empty") {
			if (st.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (s == "top") {
			if (st.empty())
				cout << "-1\n";
			else
				cout << st.top() << "\n";
		}
	}
	
	return 0;
}