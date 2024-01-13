#include <iostream>
#define MAX 1000000
using namespace std;

int n, l, ans;
int c;
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		c += arr[i];
		if (i >= l)
			c -= arr[i - l];
		if (c >= 129 && c <= 138)
			ans++;
	}
	cout << ans;
	return (0);
}