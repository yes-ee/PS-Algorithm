#include <iostream>
#define MAX 10

using namespace std;

int n, k, cnt;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > k)
			continue;
		if (k == 0)
			break;
		cnt += k / arr[i];
		k = k % arr[i];
	}
	cout << cnt;
	return 0;
}