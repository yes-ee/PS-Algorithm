// two pointer

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
ll arr[5000];
ll sum, ans = 987654321987;
int a, b, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n - 2; i++) {
		int st = i + 1;
		int end = n - 1;

		while (st < end) {
			sum = arr[st] + arr[end] + arr[i];
			if (abs(sum) < ans) {
				a = arr[i];
				b = arr[st];
				c = arr[end];
				ans = abs(sum);
			}
			if (sum == 0) {
				cout << a << " " << b << " " << c;
				return 0;
			}
			if (sum < 0) st++;
			else end--;
		}
	}
	cout << a << " " << b << " " << c;
	return 0;
}