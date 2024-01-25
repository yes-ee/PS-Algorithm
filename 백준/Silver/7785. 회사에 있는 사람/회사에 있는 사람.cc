#include <iostream>
#include <set>
#include <string>

using namespace std;

int n;
set<string, greater<string>> st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string a, b;
	while (n--) {
		cin >> a >> b;

		if (b == "enter") {
			st.insert(a);
		} else {
			st.erase(a);
		}
	}

	for (auto c : st) {
		cout << c << "\n";
	}

	return 0;
}