#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> st;
int idx = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> n;
	while (n--) {
		cin >> a;

		if (a == idx) {
			idx++;
		} else {
			if (!st.empty() && a > st.top()) {
				cout << "Sad";
				return 0;
			}
			else
				st.push(a);
		}
		while (!st.empty()) {
			if (st.top() == idx) {
				st.pop();
				idx++;
			} else break;
		}
	}
	cout << "Nice";
	return 0;
}