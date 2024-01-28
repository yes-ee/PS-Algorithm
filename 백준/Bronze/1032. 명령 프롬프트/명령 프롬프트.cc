#include <iostream>
#include <vector>

using namespace std;

int n;
string ans;
vector<string> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	int flag= 0;

	for (int i = 0; i < v[0].size(); i++) {
		flag = 0;
		char pre = v[0][i];
		for(int j = 1; j <n	; j++) {
			if (pre != v[j][i]) {
				flag = 1;
				break;
			}
		}

		if (flag) ans += "?";
		else ans += pre;
	}

	cout << ans;

	return 0;
}