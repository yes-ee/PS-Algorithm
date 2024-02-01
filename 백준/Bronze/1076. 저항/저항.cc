#include <iostream>
#include <map>

using namespace std;

map<string, pair<string, string>> m;

int main() {
	m["black"] = {"0", ""};
	m["brown"] = {"1", "0"};
	m["red"] = {"2", "00"};
	m["orange"] = {"3", "000"};
	m["yellow"] = {"4", "0000"};
	m["green"] = {"5", "00000"};
	m["blue"] = {"6", "000000"};
	m["violet"] = {"7", "0000000"};
	m["grey"] = {"8", "00000000"};
	m["white"] = {"9", "000000000"};

	string a, b, c;
	cin >> a >> b >> c;

	string ans = "";
	ans += m[a].first + m[b].first + m[c].second;

	int flag = 0;

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == '0' && !flag) continue;
		else {
			flag = 1;
			cout << ans[i];
		}
	}

	if (!flag)
		cout << "0";

	return 0;
}