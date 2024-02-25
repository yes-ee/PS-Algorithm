// ccw

#include <iostream>

using namespace std;
using ll=long long;

ll x1, x2, x3, y1, y2, y3;

ll ccw(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
	return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	ll ret = ccw(x1, x2, x3, y1, y2, y3);

	if (ret > 0)
		cout << "1";
	else if (ret < 0)
		cout << "-1";
	else
		cout << "0";

	return 0;
}