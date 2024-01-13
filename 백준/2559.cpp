#include <iostream>
#define MAX 100000
using namespace std;

int n, k;
int arr[MAX];
int sum[MAX];
int l;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i != 0)
			sum[i] = sum[i-1] + arr[i];
		else
			sum[i] = arr[i];
	}

	l = sum[k - 1];	//처음 k개의 값

	for (int i = k; i < n; i++)
		l = max(l, sum[i] - sum[i - k]);

	cout << l;

	return 0;
}