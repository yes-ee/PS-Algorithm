// two pointer

#include <iostream>

using namespace std;

int n;
int arr[100000];
int s, e, sum;
int a, b, m = 2147000000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	e = n - 1;

	while (s < e) {
		sum = arr[s] + arr[e];

		if (abs(sum) < abs(m)) {
			a = s;
			b = e;
			m = sum;
		}

		if (sum == 0) {
			break;
		} else if (sum < 0) {
			s++;
		} else {
			e--;
		}
	}

	cout << arr[a] << " " << arr[b];

	return 0;
}