#include <iostream>
#include <deque>
#include <string>

using namespace std;

int start = 1; // 시작 위치 - front(1), back(-1);
int t, n, num, flag;
char c;
string s, tmp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		deque<int> dq;
		start = 1;
		flag = 0;
		cin >> s >> n;
		while (n--) {
			cin >> c >> num;
			dq.push_back(num);
		}
		cin >> tmp;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				start *= -1;
			}
			else {
				if (dq.empty()) {
					flag = 1;
					break;
				}
				if (start == 1) // front부터 시작
					dq.pop_front();
				else if (start == -1)
					dq.pop_back();
			}
		}

		if (flag) {
			cout << "error\n";
			continue;
		}

		cout << "[";
		while (!dq.empty()) {
			if (start == 1) {
				cout << dq.front();
				dq.pop_front();
			}
			else {
				cout << dq.back();
				dq.pop_back();
			}

			if (dq.empty())
				break;
			else
				cout << ",";
		}
		cout << "]\n";
	}

	return 0;
}