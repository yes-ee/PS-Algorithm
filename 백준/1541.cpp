#include <iostream>
#include <string>

using namespace std;

int ans, num, sum, flag;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || i == s.length()) {	//한 숫자를 모두 입력받으면 결과 계산
			if (flag) {	//- 하는 경우
				ans -= num;
				num = 0;
			}
			else {	//+ 하는 경우
				ans += num;
				num = 0;
			}
			if (s[i] == '-')
				flag = 1;
		}
		else {
			num *= 10;
			num += s[i] - '0';
		}
	}
	cout << ans;
	return 0;
}