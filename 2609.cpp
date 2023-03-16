#include <iostream>
using namespace std;

int a, b, small, large;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;

	int num = min(a, b);

	for (int i = 1; i <= num; i++)
	{
		if (a % i == 0 && b % i == 0)
			large = i;
	}
	small = large * (a / large) * (b / large);

	cout << large << "\n"
			 << small;

	return 0;
}