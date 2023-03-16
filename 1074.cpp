#include <iostream>
using namespace std;

int n, r, c, ans, lo, len;

void recur()
{
	if (n == 1)
	{
		ans += 2 * r + c;
		return;
	}

	len = 1 << (n - 1);
	if (r / len == 0)
	{
		if (c / len == 0)
			lo = 0;
		else
			lo = 1;
	}
	else
	{
		if (c / len == 0)
			lo = 2;
		else
			lo = 3;
	}

	ans += (len * len * lo);
	r = r % len;
	c = c % len;
	n--;
	recur();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> r >> c;

	recur();

	cout << ans;

	return 0;
}