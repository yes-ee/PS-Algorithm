#include <bits/stdc++.h>

using namespace std;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	int xa, xb, xc;
	cin >> xa >> xb >> xc;

	int ya, yb, yc;
	cin >> ya >> yb >> yc;

	int ans = 0;

	if (ya - xa > 1000) {
		cout << "gg";
		return 0;
	} else if (ya - xa == 1000) {
		if (yb > xb) {
			cout << "gg";
			return 0;
		} else if (yb == xb) {
			if (yc >= xc) {
				cout << "gg";
				return 0;
			}
		}
	}

	for (int i = xa; i < ya; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {
			ans += 366;
		} else {
			ans += 365;
		}
	}

	int xday = 0;
	int yday = 0;
	for (int i = 1; i < xb; i++) {
		xday += day[i];
	}
	xday += xc;
	if (xa % 400 == 0 || (xa % 4 == 0 && xa % 100 != 0)) {
		if (xb > 2) {
			xday += 1;
		}
	}
	for (int i = 1; i < yb; i++) {
		yday += day[i];
	}
	yday += yc;
	if (ya % 400 == 0 || (ya % 4 == 0 && ya % 100 != 0)) {
		if (yb > 2) {
			yday += 1;
		}
	}
	ans -= xday - yday;
	cout << "D-" << ans;

	return 0;
}