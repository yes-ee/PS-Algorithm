#include <bits/stdc++.h>

using namespace std;

int m, n;
string s;
int mv;
int x, y, dr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	cin >> m >> n;
	while(n--) {
		cin >> s >> mv;
		if(s == "MOVE") {
			x += dx[dr] * mv;
			y += dy[dr] * mv;
		} else if(s == "TURN") {
			if(mv == 0) {
				dr = (dr + 3) % 4;
			} else {
				dr = (dr + 1) % 4;
			}
		}
		if (x < 0 || x >= m || y < 0 || y >= m) {
			cout << -1;
			return 0;
		}
	}

	cout << x << " " << y;

	return 0;
}