#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t, x, y;

	cin >> t;

	while (t--)
	{
		cin >> x >> y;
		int dif, n, ans;
		int tr;
		double sq;

		dif= y - x;
		sq = sqrt(dif);
		tr = trunc(sq) + 1;

		if (sqrt(dif) == trunc(sq))
			ans = 2 * (tr - 2) + 1;
		else if (tr * tr - tr < dif)
			ans = 2 * (tr - 1) + 1;
		else
			ans = 2 * (tr - 1);

		cout << ans << "\n";
	}
	return 0;
}