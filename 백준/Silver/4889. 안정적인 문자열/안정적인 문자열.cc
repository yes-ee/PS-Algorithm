// dfs stack

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string s;
int cnt, ans;
vector<char> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> s;

		for (char c: s) {
			if (c == '-') {
				return 0;
			}
			
		}

		cnt++;
		stack<char> st;
		ans = 0;

		for (char c : s) {
			if (c == '{')
				st.push(c);
			else {
				if (st.empty()) {
					ans++;
					st.push('{');
				} else
					st.pop();
			}
		}
		
		while (!st.empty()) {
			char c = st.top();
			if (c == '{')
				ans++;
			st.pop();
			st.pop();
		}


		cout << cnt << ". " << ans << "\n";
	}
		
	return 0;
}