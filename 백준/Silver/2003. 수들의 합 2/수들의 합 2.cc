// two pointer

#include <iostream>

using namespace std;

int n, cnt;
long long m, sum;
int arr[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s = 0;
	int e = 0;

	while (e <= n) {
		if (sum < m) {
			sum += arr[e];
			e++;
		} else if (sum > m) {
			sum -= arr[s];
			s++;
		} else {
			cnt++;
			sum -= arr[s];
			s++;
		}
	}

	cout << cnt;

	return 0;
}