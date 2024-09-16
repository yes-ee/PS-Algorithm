#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x1, y1, p1, q1, x2, y2, p2, q2;
	
	for (int i = 0; i < 4; i++) {
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		int xl = max(x1, x2);
		int xr = min(p1, p2);
		int yd = max(y1, y2);
		int yu = min(q1, q2);

		int xdiff = xr - xl;
		int ydiff = yu - yd;

		if (xdiff > 0 && ydiff > 0) cout << "a\n"; // 직사각형
		else if (xdiff == 0 && ydiff == 0) cout << "c\n"; // 점
		else if (xdiff < 0 || ydiff < 0) cout << "d\n"; // 겹치지 않음
		else cout << "b\n"; // 직선
	}

	return 0;
}