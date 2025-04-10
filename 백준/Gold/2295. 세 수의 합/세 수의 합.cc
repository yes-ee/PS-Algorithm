#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
int two[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<>());

	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			two[idx++] = arr[i] + arr[j];
		}
	}
	sort(two, two + n*n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = arr[i] - arr[j];
			if (binary_search(two, two + n * n, target)) {
				cout << arr[i] << "\n";
				return 0;
			}
		}
	}

	return 0;
}