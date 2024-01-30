#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	char c;
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;
			if (c == '.') continue;
			if (i % 2 == 0 && j % 2 ==0)
				cnt++;
			else if (i % 2 && j % 2)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}