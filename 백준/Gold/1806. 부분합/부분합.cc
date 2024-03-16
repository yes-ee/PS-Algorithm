#include <iostream>

using namespace std;

int n, s, sum, len = 1e9;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0;
	int e = 0;
	int cnt = 0;
	while (e <= n) {
		if (sum < s) {
			sum += arr[e++];
			cnt++;
		} else if (sum >= s) {
			len = min(len, cnt);
			sum -= arr[st++];
			cnt--;
		}
	}

	if (len == 1e9)
		cout << 0;
	else
		cout << len;

	return 0;
}