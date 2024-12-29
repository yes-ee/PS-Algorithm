#include <bits/stdc++.h>

using namespace std;

int m[8][8];
string a, b;
int n;
string cmd;
int dx[9] = {1, -1, 0, 0, 1, -1, 1, -1, 0};
int dy[9] = {0, 0, 1, -1, -1, -1, 1, 1, 0};

int ay, ax;
int by, bx;

bool chk(int y, int x) {
	if (x < 0 || x > 7 || y < 0 || y > 7) return false;
	return true;
}

void move(int dir) {
	int db = 8;
	if (!chk(ay + dy[dir], ax+dx[dir])) return;
	if ((ay + dy[dir]) == by &&  (ax + dx[dir]) == bx) db = dir;
	if (!chk(by + dy[db], bx + dx[db])) return;

	ay += dy[dir];
	ax += dx[dir];
	by += dy[db];
	bx += dx[db];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> n;

	by = 7 - (b[1] - '1');
	bx = b[0] - 'A';
	m[by][bx] = 2;

	ay = 7 - (a[1] - '1');
	ax = a[0] - 'A';
	m[ay][ax] = 1;

	while (n--) {
		cin >> cmd;

		if (cmd == "R") {
			move(0);
		} else if (cmd == "L") {
			move(1);
		} else if (cmd == "B")
			move(2);
		else if (cmd == "T")
			move(3);
		else if (cmd == "RT")
			move(4);
		else if (cmd == "LT")
			move(5);
		else if (cmd == "RB")
			move(6);
		else if (cmd == "LB")
			move(7);
	}

	cout << (char)('A' + ax) << (char)('1' + (7 - ay)) << "\n";
	cout << (char)('A' +bx) << (char)('1' + (7 - by)) << "\n";

	return 0;
}