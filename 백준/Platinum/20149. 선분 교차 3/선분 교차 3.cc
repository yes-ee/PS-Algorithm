// 선분 교차 판정

#include <iostream>

using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

pll a, b, c, d;
long double x, y;
int flag;

int ccw(pll x, pll y, pll z) {
	ll ret = (x.first * y.second + y.first * z.second + z.first * x.second) - (y.first * x.second + z.first * y.second + x.first * z.second);

	if (ret > 0)
		return -1;
	else if (ret < 0)
		return 1;
	else
		return 0;
}

void findIntersection(pll a, pll b, pll c, pll d) {
	double t, s;
	double under = (d.second - c.second) * (b.first - a.first) - (d.first - c.first) * (b.second - a.second);
	if (under == 0)
	{
		if (b == c) {
			x = b.first; 
			y = b.second;
		}
		else if (a == d) {
			x = a.first;
			y = a.second;
		} else {
			flag = 1;
		}
		return;
	}

	t = (d.first - c.first) * (a.second - c.second) - (d.second - c.second) * (a.first - c.first);
	s = (b.first - a.first) * (a.second - c.second) - (b.second - a.second) * (a.first - c.first);

	t /= under;
	s /= under;

	x = a.first + t * (b.first - a.first);
	y = a.second + t * (b.second - a.second);

	return;
}

int isIntersect(pll a, pll b, pll c, pll d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {  // 일직선인 경우
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		if (c <= b && a <= d) {
			findIntersection(a, b, c, d);
			return 1;
		}
		return 0;
	}

	if (ab <= 0 && cd <= 0) {
		findIntersection(a, b, c, d);
		return 1;
	}

	return 0;
}

int main() {
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;

	int ret = isIntersect(a, b, c, d);

	cout << ret << "\n";
	cout.precision(11);
	if (ret && !flag)
		cout << x << " " << y;

}