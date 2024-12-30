#include <bits/stdc++.h>

using namespace std;

int xs, xl, ys, yl;
int x, y;
int t, ans, dir;
string s;

void mv(int n) {
	if (dir == 0) y += n;
	else if (dir == 2) y -= n;
	else if (dir == 1) x += n;
	else x -= n;

	xs = min(x, xs);
	xl = max(x, xl);
	ys = min(y, ys);
	yl = max(y, yl);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> s;
		xs = xl = ys = yl = dir = x = y = 0;

		int len = s.length();

		for (int i = 0; i < len; i++) {
			char cmd = s[i];

			if (cmd == 'L') dir = (dir + 3) % 4;
			else if (cmd == 'R') dir = (dir + 1) % 4;
			else if (cmd == 'F') mv(1);
			else mv(-1);
		}

		ans = (xl - xs) * (yl - ys);
		
		cout << ans << "\n";
	}
	return 0;
}