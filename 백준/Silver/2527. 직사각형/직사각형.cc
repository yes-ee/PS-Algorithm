#include <iostream>

using namespace std;

char ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x1, y1, p1, q1, x2, y2, p2, q2;
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
			swap(p1, p2);
			swap(q1, q2);
		}
		if (x1 == x2) {
			if (y1 > y2) {
				swap(x1, x2);
				swap(y1, y2);
				swap(p1, p2);
				swap(q1, q2);
			}
			if (y1 == y2) {
				ans = 'a';
			} else {
				if (q1 < y2) {
					ans = 'd';
				} else if (q1 == y2) {
					ans = 'b';
				} else {
					ans = 'a';
				}
			}
		} else {
			if (p1 < x2) {
				ans = 'd';
			} else if (p1 == x2) {
				if (q1 < y2) {
					ans = 'd';
				} else if (q1 == y2) {
					ans = 'c';
				} else {
					if (q2 < y1) {
						ans = 'd';
					} else if (y1 == q2) {
						ans = 'c';
					} else {
						ans = 'b';
					}
				}
			} else {
				if (y2 == q1 || q2 == y1) {
					ans = 'b';
				} else if (y2 > q1 || q2 < y1) {
					ans = 'd';
				} else {
					ans = 'a';
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}