#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++) {
		ans += a[i];
		if (a[i] == b.back()) {
			bool flag = true;
			for (int j = 0; j < b.size(); j++) {
				if (ans[ans.size() - b.size() + j] != b[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < b.size(); j++)
					ans.pop_back();
			}
		}
	}

	if (ans.size())
		cout << ans;
	else
		cout << "FRULA";

	return 0;
}