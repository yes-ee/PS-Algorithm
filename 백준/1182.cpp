#include <iostream>

using namespace std;

int n, s, cnt, sum;
int arr[20];

void getnum(int idx) {
	sum += arr[idx];
	if (sum == s)
		cnt++;

	for (int i = idx + 1; i < n; i++)
		getnum(i);
	sum -= arr[idx];
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		getnum(i);

	cout << cnt;

	return 0;
}