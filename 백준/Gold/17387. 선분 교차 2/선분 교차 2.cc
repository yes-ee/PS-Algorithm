// 선분 교차 판정

#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll a, b, c, d;

int ccw(pll x, pll y, pll z)
{
	ll ret = (x.first * y.second + y.first * z.second + z.first * x.second) - (y.first * x.second + z.first * y.second + x.first * z.second);

	if (ret > 0)
		return -1;
	else if (ret < 0)
		return 1;
	else
		return 0;
}

int isIntersect(pll a, pll b, pll c, pll d)
{
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0)
	{ // 일직선인 경우
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);

		return c <= b && a <= d;
	}

	return ab <= 0 && cd <= 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;

	cout << isIntersect(a, b, c, d);

	return 0;
}